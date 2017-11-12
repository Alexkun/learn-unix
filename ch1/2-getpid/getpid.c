/*************************************************************************
	> File Name: getpid.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 日 11/12 22:29:16 2017
 ************************************************************************/

#include "../../apue.3e/include/apue.h"

int main(void)
{
	printf("hello world form process ID %ld\n", (long)getpid());
	exit(0);
}


