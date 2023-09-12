/**
 *
 *
 *
 *
 *
 */
char *getFirstCharPosition(char *startChar, char *delimiter)
{
	/* declare variables */
	char *charInFirstPosition;


	/* initialize variables */
	charInFirstPosition = startChar;

	while (*charInFirstPosition == *delimChar)
		charInFirstPosition++;

	if (*charInFirstPosition == '\0')
		return (NULL);
	startChar = charInFirstPosition;

	return (startChar);
}
/**
 *
 *
 *
 *
 *
 */
int charCount(char *str, char *delim)
{
	/* declare variables */
	char *start, *scanner;
	static char *nextStart;
	int charCount;

	/* initialize variables */
	start = NULL;
	scanner = NULL;
	charCount = 0;

	if (str == NULL)
		start = nextStart;
	else
		start = str;

	if (*start = '\0')
		return (-1);

	/* skip spaces or empty strings */
	/* get point the first non-delim character in the string */
	scanner = getFirstCharPosition(start, delim);
	if (scanner == NULL)
		return (-1);

	/* count the non-null or non-space characters in the string */
	while (*scanner != *delim && *scanner != '\0')
	{
		charCount++;
		scanner++;
	}

	nextStart = scanner;

	return (charCount);
}
/**
 *
 *
 *
 *
 *
 *
 */
char *_strtok(char *str, char *delim)
{
	/* declare variables */
	static char *ptrRecord;
	int count;
	char *ptrToFirstChar, *start;



	count = 0;
	start = str;


	if (start == NULL)
		start = ptrRecord;

	if (*start == '\0')
		return (NULL);


	/* get the pointer to the first non-delim character */
	ptrToFirstChar = getFirstCharPosition(start, delim);
	if (ptrToFirstChar == NULL)
		return (NULL);


	/* return the count of characters in the word including the delimiter */
	count = charCount(ptrToFirstChar, delim);

	/* null terminate the word */
	if (*(ptrToFirstChar + count) == *delim)
	{
		*(ptrToFirstChar + count) = '\0';
		count++;
	}

	/* store the pointer to the next character after the null byte */
	ptrRecord = (ptrToFirstChar + count);


	return (ptrToFirstChar);
}
