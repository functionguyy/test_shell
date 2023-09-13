#include "main.h"

int main(void)
{
	pid_t pid;
	int status, n;
	char **ep;


	char *argv[] = {"/bin/ls","/tmp", NULL};

	n = 0;

	while (n < 2)
	{
		pid = fork();

		wait(&status);
		if (pid == -1)
		{
			perror("fork");
			/*printf("I'm the parent\n");*/
		}
		if (pid > 0)
		{
			printf("I'm the parent\n");
			/*_exit(status);*/
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("execve");
			_exit(status);

		}
			/*printf("I'm child!\n");*/
			/*perror("fork");*/
		n++;
	}

	return (0);
}
