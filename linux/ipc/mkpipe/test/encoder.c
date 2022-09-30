#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define FALSE 0
#define TRUE  1


// Default port. Assumes one QSB plugged in
// and no other USB devices posing as serial
// devices.
#define SERIAL_PORT "/tmp/myfifo" //"/dev/ttyUSB0"

// The response from a QSB has the general format:
// 
//     Element: Response  Register  Data  TimeStamp '!'  EOR
//     Bytes  :     1         2       8       8      1   1..2
//
//
// Response, Register, Data, and '!' are always present.
//
// The rest of the elements are determined by the EOR (15) register.
// Each feature is enabled with a bit=1 or disabled with a bit=0.  
// The default value is: CR/LF = 0x03.
// 
// BITS:   B3 B2 B1 B0
// 
// B0 = Line Feed
// B1 = Carriage Return
// B2 = 4-byte Time Stamp appended to the response
// B3 = Spaces between returned fields
// 
// The timestamp is a 4-byte value but is appended to the 
// packet as an 8-byte hex string.
// 
// If spaces are used, the resulting format is:
// 
//   Response[space]Register[space]Data[space]TimeStamp[space]!EOR
// 
// 
// The number below is size of the longest possible response 
// received from the QSB when all terminators are on and spaces
// separate the elements. It also allows for the string termination.
const int BUFFER_SIZE = 27;


// The USB link between the QSB and the computer introduces
// considerable lag. So, we need to wait a bit when sending
// an instruction before we get the response. The value of
// 5 ms is empirical and may need adjustment on other systems.
const int FIVE_MILLISECONDS = 5000;


// How many times we will try a non-blocking read of the 
// device before we call it a failed operation.
const int MAX_READ_TRIES = 10;



// Rather than getting into complications reading the
// keyboard for input, we will just trap Ctrl+C and 
// notify the app when the user is done.
int CloseRequested = FALSE;



void printQsbError(char* errorMessage)
{
        printf("%s: %d - %s\n", errorMessage, errno, strerror(errno));
        exit(-1);
}




// The QSB presents itself to the system as a vanilla
// UART and we can talk to it using the standard 
// POSIX IO functions.
//
// In the two utilitarian functions below, 'qsb' is
// a standard UNIX file handle pointing to the serial
// port where the devices is hosted.


void sendQsbInstruction(int qsb, char* command)
{
    // Create a padded instruction string that includes
    // CR+LF. The QSB will be happy with just CR or LF too.
    char* qsbCommand = (char *)malloc(strlen(command) + 3);
    sprintf(qsbCommand, "%s\r\n", command);

    int ioResult = write(qsb, qsbCommand, strlen(qsbCommand));
	//TODO
	//printf("written: %s\n",qsbCommand);
    free(qsbCommand);

    if (ioResult < 0)
    {
        printQsbError("Error writing to QSB device");
    }
}


void readQsbResponse(int qsb, char* response, int responseSize)
{
	 //tcflush(qsb, TCIFLUSH);
    int i = 0;
    int ioResult;
    do
    {
        ioResult = read(qsb, response, responseSize);
        // This delay is to give some time to the device to
        // pipe the information to the serial port.
        usleep(5000);
        i++;
    } while (ioResult < 0 && errno == EAGAIN);// && i < MAX_READ_TRIES);

    if (i == MAX_READ_TRIES)
    {
        printQsbError("Error reading from QSB device");
    }

    // Remove the trailing CR+LF if any, and trim to proper size.
    int end = strcspn(response, "\r\n");
    response[end] = '\0';
	
    if (ioResult < responseSize)
    {
        response[ioResult] = '\0';
    }
	//TODO
	//printf("response: %s\n",response);
}


// Every instruction sent to the QSB is acknowledged 
// with a corresponding response string. We then send
// the instruction and retrieve the response as a 
// single command transaction.
void qsbCommand(int qsb, char* command, char* response, int responseSize)
{
    sendQsbInstruction(qsb, command);
    usleep(5000);
    readQsbResponse(qsb, response, responseSize);
}

//Extract the response value from the response packet.
void dataExtract(char* response)
{
	int i=5,j=0;
	char res[15] = "0x";
	
	strncpy(res+2,response+5,8);
	strcpy(response,res);
}

//Convert hexadecimal response to Decimal Value.
int hexToDec(char*response)
{
	return (int)strtol(response, NULL, 16);
}

//Calculate the length using the count value.
float calcLength(int count)
{
	float PPI;
	int PPR = 10;
	float Length;
	float Radius = 1.84;
	
	PPI = PPR/(2*3.14*Radius);
	Length = count/PPI;
	return Length/12;
}

//calculate time in seconds from the timestamp count.
float calcTime(int count)
{
//printf("time is %f\r",count*0.00195);
	return count*0.00195; //count is increased by one per 1.95ms
}

//Calculate the speed value for the rope. 
float calcSpeed(float length, float time)
{
	return length/time;
}

void ctrlCHandler(int signal)
{
    CloseRequested = TRUE;
}


// *************************************************
// 
//  General flow of operation:
//   1. Open the port and configure it.
//      The QSB UART wants 230.4K Baud, 8-n-1
//   2. Set up the QSB to read an encoder.
//   3. Loop polling and printing the current
//      encoder count.
//   4. Upon close request, close the port and
//      exit. 
// 
// *************************************************

int main (int argc, char *argv[])
{
	system("clear");
	time_t sec1, sec2;
	
	sec1 = time(NULL);
	
	
    // Register the Ctrl-C handler.
    signal(SIGINT, ctrlCHandler);
    
    int Count = 0;
    int Timestamp = 0;
    
    char *command = NULL;
    char response[BUFFER_SIZE];
    char *id = NULL;
    
    float Len = 0;
    float Time = 0;
    float Speed = 0;
    
    struct termios qsbConfiguration;
    FILE *fptr = NULL;
	//char * myfifo = "/tmp/myfifo";
	//mkfifo(myfifo, 0666);
    // Open the port.
    int qsb = open(SERIAL_PORT, O_RDWR | O_NOCTTY | O_NONBLOCK);
    
    if (qsb < 0)
    {
    	printQsbError("Error opening QSB device");
    }
    else
    {
    	// Configure it.	
		/*tcgetattr(qsb, &qsbConfiguration);
		
		qsbConfiguration.c_cflag = B230400 | CS8;
		cfsetospeed(&qsbConfiguration, B230400);
		tcflush(qsb, TCIFLUSH);
		tcsetattr(qsb, TCSANOW, &qsbConfiguration);
			*/
		//File pointer for the text file.
		
		fptr = (fopen("Encoder.txt", "w"));
		
		if(fptr == NULL)
		{
			printf("Error!");
			exit(1);
		}
		else
		{
				// Read and print product information.
				// Register: VERSION (0x14)
				qsbCommand(qsb, "R14", response, BUFFER_SIZE);
				printf("Product info: %s\n", response);
				
				// Set encoder in quadrature mode.
				// Register: MODE (0x00)
				qsbCommand(qsb, "W0000", response, BUFFER_SIZE);
				printf("Quadrature response: %s\n", response);

				// Count up, 1X, Modulo-N.
				// Register: MDR0 (0x03)
				qsbCommand(qsb, "W030C", response, BUFFER_SIZE);
				printf("Count configuration: %s\n", response);

				// Set maximum count (Preset) to decimal 499
				// Register: DTR (0x08)
				qsbCommand(qsb, "W081F3", response, BUFFER_SIZE);
				printf("Maximum count: %s\n", response);

				// Clear Timestamp.
				// Register: Timestamp (0x0D)
				qsbCommand(qsb, "W0D01", response, BUFFER_SIZE);
			
				// Clear Counter.
				// Register: Clear cntr (0x09)
				qsbCommand(qsb, "W092", response, BUFFER_SIZE);
			
				puts("\nUse Ctrl+C to exit.\n\n");
				
				while (CloseRequested == FALSE)
				{
					// Read current count.
					// Register: READ ENCODER (0x0E)
					qsbCommand(qsb, "R0E", response, BUFFER_SIZE);
					dataExtract(response);
					Count = hexToDec(response);
				
					Len = calcLength(Count);
				
					// Read Timestamp.
					// Register: READ ENCODER (0x0D)
					qsbCommand(qsb, "R0D", response, BUFFER_SIZE);
					dataExtract(response);
					Timestamp = hexToDec(response);
				
					Time = calcTime(Timestamp);
					//
					sec2 = time(NULL);
					Time =sec2-sec1;
					
					
					Speed = calcSpeed(Len,Time);
					printf("\033[s");
				
					printf("\033[10;3HCount: %d\n",Count);
					printf("\033[11;3HDistance: %0.2fft\n",Len);
					printf("\033[12;3HTime: %0.2fsec\n",Time);
					printf("\033[13;3HSpeed: %0.2fft/sec",Speed);

					fprintf(fptr,"Count: %d\tDistance: %0.2fft\tTime: %0.2fsec\tSpeed: %0.2fft/sec \n",Count,Len,Time,Speed);
				}

			close(qsb);
			puts("\n");
		} 
    }
    
    return(0);
}
