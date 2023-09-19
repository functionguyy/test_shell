#include "main.h"
/**
 * createDirPath - creareturns the directory path for a command
 * @h: pointer to the head of a singly linked list containing the directory
 * pathnames in PATH environment variables
 * @mem: malloc'ed memory array where the created pathname is stored
 * @cmdName: name of the command
 * @size: byte size of mem array
 *
 * Description: the function generates the directory pathname of a command by
 * appending the cmdName to the directory string in h. The directory string in
 * h are the directory paths in PATH enviroment variable.
 * Return: returns a pointer to the string of the directory path for a command
 */
char *createDirPath(list_t *h, char **mem, char *cmdName, size_t size)
{
	size_t tempBufSize, lenCmdName;
	char *cmdDirPath, *pathnameMem, *slash;
	list_t *temp;

	lenCmdName = strlen(cmdName);
	pathnameMem = *mem;
	temp = h;
	slash = "/";

	tempBufSize = temp->len + lenCmdName + 2;
	if (tempBufSize > size)
	{
		size = tempBufSize;
		pathnameMem = realloc(pathnameMem, sizeof(char) * size);
		if (pathnameMem == NULL)
			return (NULL);
	}

	cmdDirPath = strcpy(pathnameMem, temp->str);
	if (cmdDirPath[(temp->len) - 1] != '/')
		cmdDirPath = strcat(pathnameMem, slash);
	cmdDirPath = strcat(pathnameMem, cmdName);

	return (cmdDirPath);
}
/**
 * locateCmdDirPath - return the directory pathname containing the binary file
 * of a command.
 * @h: linked list of the PATH directories
 * @cmdName: name of the command
 *
 * Return: returns the pointer to a directory pathname containing the binary
 * for a command or NULL if not found.
 */
char *locateCmdDirPath(list_t *h, char *cmdName)
{
	/* declare variables */
	list_t *temp;
	size_t bufSize, foundSig;
	char *cmdDirPath, *pathnameMem;
	struct stat st;

	/* initialize variables */
	bufSize = 512;
	cmdDirPath = NULL;
	foundSig = 0;
	temp = h;

	pathnameMem = malloc(sizeof(char) * bufSize);
	if (pathnameMem == NULL)
		return (NULL);

	while (temp != NULL && foundSig == 0)
	{
		cmdDirPath = createDirPath(temp, &pathnameMem, cmdName, bufSize);
		if (cmdDirPath == NULL)
			return (NULL);

		/**
		 * check if command file exist in PATH directory pointed to by dirPath
		 */
		if (stat(cmdDirPath, &st) == 0)
		{
			foundSig = 1;
			bufSize = strlen(cmdDirPath);
			pathnameMem = malloc(sizeof(char) * (bufSize + 1));
			if (pathnameMem == NULL)
				return (NULL);

			pathnameMem = strcpy(pathnameMem, cmdDirPath);
			free(cmdDirPath);
			cmdDirPath = pathnameMem;
			return (cmdDirPath);
		}
		temp = temp->next;
	}

	if (cmdDirPath != NULL && foundSig == 0)
		free(cmdDirPath);

	return (NULL);
}
/**
 * createPathDirList - builds a linked list of of the PATH directories
 *
 * Return: returns pointer to linked list if successful or NULL otherwise.
 */
list_t *createPathDirList(void)
{
	/* declare variables */
	char *pathDirToken, *envValue;
	list_t *head;

	/* initialize variables */
	head = NULL;
	envValue = strdup(_getenv("PATH"));
	if (envValue == NULL)
		return (NULL);
	pathDirToken = strtok(envValue, ":");

	/* build singly linked list of PATH directory pathnames */
	while (pathDirToken != NULL)
	{
		add_node_end(&head, pathDirToken);
		pathDirToken = strtok(NULL, ":");
	}

	free(envValue);
	return (head);
}
