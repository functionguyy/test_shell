#include "main.h"


int main(void)
{
	ssize_t nRead, nWrite;
	char *lineptr;
	size_t n;


	nRead = 0;
	lineptr = NULL;
	n = 0;


	printf("$ ");
	fflush(stdout);


	nRead = _getline(&lineptr, &n, STDIN_FILENO);
	if (nRead == -1)
	{
		perror("Error reading input");
		return (0);
	}

	nWrite = write(STDOUT_FILENO, lineptr, nRead);

	if (nWrite == -1 || nWrite < nRead)
		return (0);

	return (0);
}
