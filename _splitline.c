/**
 *
 *
 *
 *
 *
 */
list_t *reverse_list(list_t **head)
{
	/* declare variables */
	list_t *prevNode, *nxtNode;

	/* initialize variables */
	prevNode = NULL;
	nxtNode = NULL;

	if (head == NULL || *head == NULL)
		return (NULL);

	while (*head != NULL)
	{
		/* save the address of the node that is linked to the current node */
		nxtNode = (*head)->next;

		/* change the direction of the link for the current node */
		(*head)->next = prevNode;

		/* make node previously linked to current node to take the position of
		 * the current node
		 */
		*head = nxtNode;
	}
	*head = prevNode;

	return (*head);
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

	/* tokenize string */
	token = strtok(fullStr, " ");

	/* check that string contains atleast one non-delimiter character */
	if (token == NULL)
		return (NULL);

	while (token != NULL)
	{
		add_node(&head, token);
		token = strtok(NULL, " ");
	}

	head = reverse_list(&head);

	numberOfWords = list_len(head);


	ptrArr = malloc(sizeof(char *) * (numberOfWords + 1));
	if (ptrArr == NULL)
		return (NULL);

	while (head != NULL)
	{
		temp = head;
		ptrArr[arrIdx] = temp->str;
		arrIdx++;
		head = temp->next;
	}
	ptrArr[arrIdx] = NULL;

	free_list(head);

	return (ptrArr);
}
