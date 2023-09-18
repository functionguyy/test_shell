#include "main.h"

int processExecute(char *cmdPath, char **line_arr)
{
	pid_t pid;
	int status;
	/* char **temp;*/


	/* char *argv[] = {"/bin/ls","/tmp", NULL};*/

	/* printf("line_arr[0]=%s and line_arr[1]=%s\n",line_arr[0],
	 * line_arr[1]);
	 **/

	/*n = 0;*/

	/*temp = line_arr;*/

	/* verfiy file status before fork */

	pid = fork();

	wait(&status);
	if (pid == -1)
	{
		perror("fork");
		/*printf("I'm the parent\n");*/
	}
	if (pid > 0)
	{
		/* printf("I'm the parent\n");*/
		freeArrayOfPtr(line_arr);
		/*_exit(status);*/
	}
	if (pid == 0)
	{
		if (execve(cmdPath, line_arr, environ) == -1)
			perror("execve");
		_exit(status);

	}
	/*printf("I'm child!\n");*/
	/*perror("fork");*/
	/*n++;*/

	return (0);
}
