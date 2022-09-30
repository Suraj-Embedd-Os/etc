// C program to implement one side of FIFO
// This side writes first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define LEN 10
struct data
{
	char cmd[LEN][20];
	char response[LEN][20];
};
void fill(struct data *qsb);
void search_data(char * src,char * des,struct data *qsb);
int main()
{
	struct data qsb;
	fill(&qsb);
	
    int fd;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);

    char rd_buff[20], wr_buff[20];
    while (1)
    {
        // Open FIFO for write only
        fd = open(myfifo, O_RDONLY);

        read(fd, rd_buff, sizeof(rd_buff));
		
		//printf("command recv %s\n",rd_buff);
		
		search_data(rd_buff,wr_buff,&qsb);
		
        close(fd);
		usleep(10000);
        // Open FIFO for Read only
        fd = open(myfifo, O_WRONLY);

        // Read from FIFO
        write(fd, wr_buff, strlen(wr_buff)+1);
		//printf("response send %s\n",wr_buff);
        // Print the read message
       
        close(fd);
    }
    return 0;
}

void fill(struct data *qsb)
{

	strcpy(qsb->cmd[0],"R14");
	strcpy(qsb->cmd[1],"W0000");
	strcpy(qsb->cmd[2],"W030C");
	strcpy(qsb->cmd[3],"W081F3");
	strcpy(qsb->cmd[4],"W0D01");
	strcpy(qsb->cmd[5],"W092");
	strcpy(qsb->cmd[6],"R0E");
	strcpy(qsb->cmd[7],"R0D");
	
	strcpy(qsb->response[0],"ROTARY ENCODER");
	strcpy(qsb->response[1],"PASS");
	strcpy(qsb->response[2],"PASS");
	strcpy(qsb->response[3],"1000");
	strcpy(qsb->response[4],"100");
	strcpy(qsb->response[5],"PASS");
	strcpy(qsb->response[6],"0000123200");
	strcpy(qsb->response[7],"00001232000");

}

void search_data(char * src,char * des,struct data *qsb)
{
	int end = strcspn(src, "\r\n");
    src[end] = '\0';
	int i=0;
	for(i=0;i<LEN;i++)
	{
		if(strncmp(qsb->cmd[i],src,strlen(src)-1)==0)
		{
			strcpy(des,qsb->response[i]);
			//printf("des: %s \n",des);
		}
	}
	
}
