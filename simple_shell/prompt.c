#include "main.h"
/**
 *
 *
 *
 *
 */
char *_prompt(void)
{
	ssize_t n_read;
	static char *line_ptr;
	size_t n;


	line_ptr = NULL;
	n = 0;
	errno = 0;


	while (1)
	{
		printf("OMSH$ ");
		fflush(stdout);

		n_read = getline(&line_ptr, &n, stdin);
		if (n_read == -1 && errno != 0)
		{
			perror("getline failed");
			break;
		}

		/* executes when Ctrl+D is used to signal end-of-file */
		if (n_read == -1 && errno == 0)
		{
			break;
		}

		/* n_write = write(STDOUT_FILENO, line_ptr, n_read); */

		return (line_ptr);
	}

	/*putchar('\n');*/
	free(line_ptr);

	return (NULL);
}
