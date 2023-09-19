#include "main.h"


/* implement exit */
int exit_prog(void)
{
	/* raise a signal */
	/* so the program can perform some cleanup before exiting */

	return (0);
}
/**
 * print_env - prints the environment variables and values
 *
 * Return: 0 on success.Always successful.
 */
/* implement env */
int print_env(void)
{
	/* implement env */

	/* declare variables */
	char **ep;

	/* initialize variable */
	ep = environ;

	while (*ep != NULL)
	{

		/* bring your printf function to use here */
		printf("%s\n", *ep);
		ep++;
	}

	return (0);
}
