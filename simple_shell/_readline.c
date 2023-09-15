#include "main.h"
/**
 *
 *
 *
 *
 *
 *
 *
 */
char *_readLine(void)
{
	/* declare variables */
	ssize_t n_read;
	char *line_ptr;
	size_t n;


	/* initialize variables */
	line_ptr = NULL;
	n = 0;
	errno = 0;


	/* read input command line */
	n_read = getline(&line_ptr, &n, stdin);
	if (n_read == -1 && errno != 0)
	{
		perror("getline");
		free(line_ptr);
		return (NULL);
	}

	/* executes when Ctrl+D is used to signall end-of-file */
	if (n_read == -1 && errno == 0)
	{
		free(line_ptr);
		return (NULL);
	}


	return (line_ptr);
}
