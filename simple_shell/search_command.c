#include "main.h"
/**
 *
 *
 *
 */
int executeFunc(command_t commandData, char **cmdLineArr)
{
	/* if the locationFlag is 1 */
		/* free struct data */
		/* return call proceesExecute function */

	/* if the locationFlag is 0 */
		/* free struct data */
		/* return call to builtin func */

	/* free struct data */
	/* return (0) */
}
/**
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
command_t *searchCmd(char *commandName)
{
	/* declare variables */
	command_t *commandData;

	/* initialize variables */
	commandData = malloc_checked(sizeof(command_t));


	 /* return a struct with number and character */

	/* check if command contain a forward slash */
	if (strchr(commandName, "/"))
	{
		/* do stat check on commandName */
			/* if stat check is true, assign 1 to locationFlag */
			/* assign  commandData */
		/* else free the struct data and return NULL */
	}


	/*check the builtin functions for a command name match */
	if (findCommand(commandName))
	{
		/**
		 * n will be 0 to indicate that the command is a builtin command
		 * char will be pointer to the name of the function
		 */
		commandData->command = commandName;
		commandData->locationFlag = 0;
		return (commandData);
	}

	if ((commandPath = searchPath(char *commandName)) != NULL)
	{
		/* check the path directories for the command */
		commandData->command = commandPath;
		commandData->locationFlag = 1;
		return (commandData);
	}

	/* if non of the above worked */
	/* set errno: no such file or directory */
	/* free struct data */
	return(NULL);
}



/**
 *
 *
 *
 */
int (*findCommand(char *commandName))(void)
{
	builtInFunc_t func[] = {
		{"env", env},
		{"exit", exit},
		{NULL, NULL}
	};

	size_t idx;

	idx = 0;

	while (fun[idx].funcName)
	{
		if (strcmp(command, func[idx].funcName) == 0)
			return (func[idx].builtInFunc);
		idx++;
	}

	return (NULL);
}
/**
 *
 *
 *
 *
 */
char *searchPath(char *commandName)
{
	/* search the path directories for the command */
	/* declare variables */
	list_t *head, *temp;
	size_t lenCmdName, bufSize, foundSig;
	char *dirPath;


	/* initialize variables */
	lenCmdName = strlen(commandName);
	head = createPathDirList();
	bufSize = 0;
	dirPath = NULL;
	foundSig = 0;


	temp = head;

	while (temp != NULL && foundSig == 0)
	{
		tempBufSize = temp->n + lenCmdName + 1;
		if (bufsize == 0)
			/* malloc mem */

		if (tempBufSize > bufSize)
			/* realloc mem to tempBufSize */

		pathname = strcpy(pathnameMem, temp->str);
		pathname = strconcat(pathnameMem, commandName);

		/* check if command file exist in PATH directory */
		if (stat(pathname, &s) == 0)
		{
			foundSig = 1;
			dirPath = pathName;
		}
		temp = temp->next;
	}

	return (dirPath)
}
