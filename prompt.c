#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main(void)
{
	ssize_t n_read, n_write;
	char *line_ptr;
	size_t n;


	line_ptr = NULL;
	n = 0;
	errno = 0;


	while (1)
	{
		printf("$ ");
		fflush(stdout);

		n_read = getline(&line_ptr, &n, stdin);
		if (n_read == -1 && errno != 0)
			perror("getline failed");

		/* executes when Ctrl+D is used to signal end-of-file */
		if (n_read == -1 && errno == 0)
		{
			putchar('\n');
			_exit(EXIT_SUCCESS);
		}

		n_write = write(STDOUT_FILENO, line_ptr, n_read);
	}

	/*putchar('\n');*/

	return (0);
}
