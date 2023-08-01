
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int 
main(void)
{
	int fd;
	if ((fd = creat("file.hole", FILE_MODE)) < 0)
	{
		perror("creat()\n");
		return -1;
	}
	
	if (write(fd, buf1, 10) != 10)
	{
		perror("write()\n");
		return -1;
	}
	/* offset now = 10 */

	if (lseek(fd, 16384, SEEK_SET) == -1)
	{
		perror("lseek()\n");
		return -1;
	}
	/* offset now = 16384 */
	if (write(fd, buf2, 10) != 10)
	{
		perror("write()\n");
		return -1;
	}
	/* offset now = 16394 */
	exit(0);

}
