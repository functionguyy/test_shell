#include "main.h"


/* implement exit */




/* implement env */
int env(void)
{
	/* declare variables */
	char **ep;

	/* initialize variable */
	ep = environ;

	while (*ep != NULL)
	{

		/* bring your printf function to use here */


	}


	exit(EXIT_SUCCESS);
}
