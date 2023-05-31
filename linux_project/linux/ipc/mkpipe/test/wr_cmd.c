// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
    int fd1;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);

    char rd_buff[20], wr_buff[20];
    
    while (1)
    {
        // First open in read only and read
        fd1 = open(myfifo,O_WRONLY);
		fgets(wr_buff, 80, stdin);
		write(fd1, wr_buff, strlen(wr_buff)+1);
        

        // Print the read string and close
        printf("COMMAND send: %s\n", wr_buff);
        close(fd1);

     
        // string taken from user.
        fd1 = open(myfifo,O_RDONLY);
        
        read(fd1, rd_buff, 80);
		printf("RESPONSE RECIEVE: %s\n", rd_buff);
        close(fd1);
    }
    return 0;
}
