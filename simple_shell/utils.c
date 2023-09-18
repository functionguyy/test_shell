#include "main.h"
/**
 * malloc_checked - function that allocates memory using malloc
 * @b: size of the memory bytes to be allocated
 *
 * Return: pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	/* declare variable */
	void *memory;

	/* initialize variable */
	memory = NULL;

	/* request memory allocation */
	memory = malloc(b);

	/* confirm memory allocation */
	if (memory == NULL)
		exit(98);

	/* return pointer to allocated memory */
	return (memory);
}
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

	ptrArr = malloc_checked(sizeof(char *) * arraySize);

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
