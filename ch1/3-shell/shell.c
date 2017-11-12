/*************************************************************************
	> File Name: shell.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 日 11/12 22:33:46 2017
 ************************************************************************/

#include"../../apue.3e/include/apue.h"
#include <sys/wait.h>

int main(void)
{
	char	buf[MAXLINE];
	pid_t	pid;
	int		status;

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL) {

		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0; /* replace newline with null */

		if ((pid = fork()) < 0) {
			err_sys("fork error");
		} else if (pid == 0) {
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute: %s", buf);
			exit(127);
		}

		/* parent */
		if ((pid = waitpid(pid, &status, 0))< 0)
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}
