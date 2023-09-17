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
/**
 *
 *
 *
 */
char *_getenv(char *envVar)
{
	char **ep, *varName, *envValue, *line;
	size_t valueIdx;

	ep = environ;
	envValue = NULL;


	while (*ep != NULL)
	{
		varName = strtok(*ep, "=");
		if (strcmp(varName, envVar) == 0)
		{
			/* enviroment variables are of the nature name=var */
			valueIdx = strlen(varName) + 1;
			line = *ep;
			envValue = (line + valueIdx);
			break;
		}
		ep++;
	}

	return (envValue);
}
/**
 *
 *
 *
 *
 *
 *
 *
 */
char **createArrayOfLineTokens(list_t *h)
{
	/* declare variables */
	list_t *temp;
	char **ptrArr;
	size_t arraySize, arrIdx;


	/* initialize variables */
	temp = h;
	arrIdx = 0;
	arraySize = list_len(h) + 1;

	ptrArr = malloc(sizeof(char *) * arraySize);
	if (ptrArr == NULL)
		return (NULL);

	while (temp != NULL)
	{
		ptrArr[arrIdx++] = strdup(temp->str);
		temp = temp->next;
	}
	/* null-terminate the array */
	ptrArr[arrIdx] = NULL;

	free_list(h);

	return (ptrArr);
}
/**
 *
 *
 *
 *
 *
 *
 */
list_t *createListOfLineTokens(char *str, char *delim)
{
	/* declare variables */
	char *line, *token;
	list_t *head;

	/* initialize variables */
	line = str;
	head = NULL;


	/* tokenize string */
	token = strtok(line, delim);
	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, delim);
	}

	return (head);
}
