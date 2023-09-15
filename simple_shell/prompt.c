#include "main.h"
/**
 *
 *
 *
 *
 */
char *_prompt(void)
{
	/*ssize_t n_read; */
	char *line_ptr;
	/*size_t n;*/


	/*line_ptr = NULL;*/
	/* n = 0;*/
	/*errno = 0;*/


	printf("OMSH$ ");
	fflush(stdout);

	/* build a readline function */
	line_ptr = _readLine();

	/* n_read = getline(&line_ptr, &n, stdin);
	if (n_read == -1 && errno != 0)
	{
		perror("getline failed");
		free(line_ptr);
		return (NULL);
	}*/

	/* executes when Ctrl+D is used to signal end-of-file */
	/*if (n_read == -1 && errno == 0)
	{
		free(line_ptr);
		return (NULL);
	}*/

	/* n_write = write(STDOUT_FILENO, line_ptr, n_read); */


	/*putchar('\n');*/
	/*free(line_ptr);*/

	return (line_ptr);
}
