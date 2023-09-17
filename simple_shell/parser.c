#include "main.h"
/**
 *
 *
 *
 *
 *
 *
 */
void overwriteNewlineByte(char *str)
{
	/* declare variables */
	char *newlineStrPtr;
	size_t idx;

	/* initialize variables */
	newlineStrPtr = str;
	idx = 0;

	/* get index of new line character */
	while (newlineStrPtr[idx] != '\n')
		idx++;

	/* overwrite the newline character with a null-byte */
	newlineStrPtr[idx] = '\0';
}
/**
 *
 *
 *
 *
 *
 *
 */
char **parseLine(char *str, char *delimiter)
{
	/* declare variables */
	char *fullStr, **ptrArr;
	list_t *head;


	/* initialize variables */
	fullStr = str;
	head = NULL;

	/* confirm argument passed is not empty */
	if (fullStr == NULL || *fullStr == '\0')
		return (NULL);

	/*remove new line character from line */
	if (strchr(fullStr, '\n') != NULL)
		overwriteNewlineByte(fullStr);

	/* check that string contains atleast one non-delimiter character */
	if (isEmptyString(fullStr, delimiter) == -1)
		return (NULL);

	head = createListOfLineTokens(fullStr, delimiter);
	ptrArr = createArrayOfLineTokens(head);

	/* free input buffer */
	free(fullStr);


	return (ptrArr);
}
