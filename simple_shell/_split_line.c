#include "main.h"

void chopOfNewlineCharacter(char **str)
{
	/* declare variables */
	char *newlineStr;
	size_t idx, strCount;


	newlineStr = *str;
	idx = 0;
	strCount = 0;


	while (newlineStr[idx] != '\n')
	{
		idx++;
		strCount++;
	}

	/* subtract the count for the newline character */
	strCount -= 1;

	/* allocate new buffer */
	buf = malloc(sizeof(char) * strCount);
	if (buf == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* copy all characters  except newline character */
	buf = strncpy(buf, newlineStr, strCount);


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
	chopOffNewlineCharacter(fullStr);
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

	/* reverse_list(&head);*/

	numberOfWords = list_len(head);


	ptrArr = malloc(sizeof(char *) * (numberOfWords + 1));
	if (ptrArr == NULL)
		return (NULL);

	while (head != NULL)
	{
		temp = head;
		ptrArr[arrIdx++] = temp->str;
		head = temp->next;
	}
	ptrArr[arrIdx] = NULL;

	printf("ptrArr[0]=%s", ptrArr[0]);
	free_list(head);

	return (ptrArr);
}
