
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#define MAXLINE 100

#define DEF_PAGER "/bin/more" /* default pager program */

int main(int argc, char *argv[])
{
		int n;
		int fd[2];
		pid_t pid;
		char *pager, *argv0;
		char line[MAXLINE];
		FILE *fp;
		if (argc != 2){
		perror("usage: a.out <pathname>");
		exit(0);
		}
		
		if ((fp = fopen(argv[1], "r")) == NULL){
		printf("can’t open %s\n", argv[1]);
		exit(0);
		}
		
		if (pipe(fd) < 0){
		perror("pipe error\n");
		exit(0);
		}
		
		if ((pid = fork()) < 0) {
		perror("fork error");
		exit(0);
		} 
		else if (pid > 0) { /* parent */
			close(fd[0]); /* close read end */
			/* parent copies argv[1] to pipe */
			while (fgets(line, MAXLINE, fp) != NULL) {
			n=strlen(line);
			if (write(fd[1], line, n) != n)
			perror("write error to pipe\n");
			}
			if (ferror(fp))
			perror("fgets error");
			close(fd[1]); /* close write end of pipe for reader */
			if (waitpid(pid, NULL, 0) < 0)
			perror("waitpid error\n");
			exit(0);
		} 
		else { /* child */
			close(fd[1]); /* close write end */
			if (fd[0] != STDIN_FILENO) {
			if (dup2(fd[0], STDIN_FILENO) != STDIN_FILENO)
			perror("dup2 error to stdin\n");
			close(fd[0]); /* don’t need this after dup2 */
			}
			/* get arguments for execl() */
			if ((pager = getenv("PAGER")) == NULL)
			pager = DEF_PAGER;
			if ((argv0 = strrchr(pager, '/')) != NULL)
			argv0++; /* step past rightmost slash */
			else
			argv0 = pager; /* no slash in pager */
			if (execl(pager, argv0, (char *)0) < 0)
			printf("execl error for %s\n", pager);
		}
exit(0);

}

