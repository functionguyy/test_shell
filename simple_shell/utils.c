#include "main.h"
/**
 *
 *
 *
 *
 *
 *
 */
ssize_t isEmptyString(char *str, char *delimiter)
{
	/* declare variables */
	char *stringPtr;


	/* initialize variables */
	stringPtr = str;

	/* scan the string */
	while (*stringPtr == *delimiter)
		stringPtr++;

	if (*stringPtr == '\0')
		return (-1);

	return (0);
}


/* implement function that calls builtin command */
/* it will have a null terminated array of function pointers */

