/*
 * test_receive.c
 *
 * This test goes with test_send.c.
 * test_send.c does a loop of mq_sends,
 * and test_receive.c does a loop of mq_receives.
 */
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <sched.h>
#include <sys/mman.h>
#include <sys/fcntl.h>
#include <signal.h>
#include <mqueue.h>
#include <errno.h>
#include<stdlib.h>

#define PMODE 0666
extern int errno;

int main()
{
	int i;
	mqd_t mqfd;
	/* Buffer to receive msg into */
	char msg_buffer[1000];
	struct mq_attr attr;
	int open_flags = 0;
	ssize_t num_bytes_received = 0;
	msg_buffer[10] = 0; /* For printing a null terminated string for testing */

	printf("START OF TEST_RECEIVE \n");

	/* Fill in attributes for message queue */
	attr.mq_maxmsg = 20;
	attr.mq_msgsize = 100;
	attr.mq_flags   = 0;

	/* Set the flags for the open of the queue.
	 * Make it a blocking open on the queue,
	 * meaning it will block if this process tries to
	 * send to the queue and the queue is full.
	 * (Absence of O_NONBLOCK flag implies that
	 * the open is blocking)
	 *
	 * Specify O_CREAT so that the file will get
	 * created if it does not already exist.
	 *
	 * Specify O_RDONLY since we are only
	 * planning to write to the queue,
	 * although we could specify O_RDWR also.
	 */
	open_flags = O_RDONLY|O_CREAT;

	/* Open the queue, and create it if the sending process hasn't
	 * already created it.
	 */
	mqfd = mq_open("myipc",open_flags,PMODE,&attr);
	if (mqfd == -1)
		{
			perror("mq_open failure from main");
			exit(0);
		};

	/* Perform the receive 10 times */
	for (i=0;i<10;i++)
		{
		num_bytes_received = mq_receive(mqfd,msg_buffer,100,0);
		if (num_bytes_received == -1)
			{
				perror("mq_receive failure on mqfd");
			}
		else
			printf("data read for iteration %d = %s \n",i,msg_buffer);
		}

	/* Done with queue, so close it */
	if (mq_close(mqfd) == -1)
		perror("mq_close failure on mqfd");

	/* Done with test, so unlink the queue,
	 * which destroys it.
	 * You only need one call to unlink.
	 */
	if (mq_unlink("myipc") == -1)
		perror("mq_unlink failure in test_ipc");

	printf("Exiting receiving process after closing and unlinking queue \n");
}