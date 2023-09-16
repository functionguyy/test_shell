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
char **splitLine(char *str)
{
	/* declare variables */
	char *fullStr, *token, **ptrArr;
	size_t numberOfWords, arrIdx;
	list_t *head, *temp;


	/* initialize variables */
	fullStr = str;
	token = NULL;
	numberOfWords = 0;
	arrIdx = 0;
	head = NULL;

	/* confirm argument passed is not empty */
	if (fullStr == NULL || *fullStr == '\0')
		return (NULL);

	/*remove new line character from line */
	if (strchr(fullStr, '\n') != NULL)
		overwriteNewlineByte(fullStr);

	/* add function that check if input is an empty string */
	/* isEmptyString() */
	/* isEmptyString() return an int -1 for false and 0 for true */
	if (isEmptyString(fullStr, " ") == -1)
		return (NULL);


	/* tokenize string */
	token = strtok(fullStr, " ");

	/* check that string contains atleast one non-delimiter character */
	if (token == NULL)
		return (NULL);

	while (token != NULL)
	{
		add_node_end(&head, token);
		token = strtok(NULL, " ");
	}

	free(fullStr);
	/* reverse_list(&head);*/
	print_list(head);

	numberOfWords = list_len(head);


	ptrArr = malloc(sizeof(char *) * (numberOfWords + 1));
	if (ptrArr == NULL)
		return (NULL);

	temp = head;
	while (temp != NULL)
	{
		/*temp = head;*/
		ptrArr[arrIdx++] = strdup(temp->str);
		temp = temp->next;
	}
	ptrArr[arrIdx] = NULL;

	printf("ptrArr[0]=%s\n", ptrArr[0]);
	free_list(head);

	return (ptrArr);
}
