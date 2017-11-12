/*************************************************************************
	> File Name: ls.c
	> Author: Y.K.Young
	> Mail: winkunkun@gmail.com
	> Created Time: 日 11/12 22:10:06 2017
 ************************************************************************/

#include<stdio.h>
#include "../../apue.3e/include/apue.h"
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR			*dp;
	struct dirent	*dirp;

	if (argc != 2)
		err_quit("usage: ls directory_name");

	if ((dp == opendir(argv[1])) == NULL)
		err_sys("can't open %s", argv[1]);

	while ((dirp == readir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);

}


