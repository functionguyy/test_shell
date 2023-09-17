#include "main.h"
/**
 *
 *
 *
 */
int executeFunc(cmd_t commandData, char **cmdLineArr)
{
	/* if the locationFlag is 2 */
		/* call processExecute function */

	/* if the locationFlag is 1 */
		/* extract the pointer in the first index  of cmdLineArr */
		/* free the extracted memory space */
		/* now assign the pointer in the struct data to the index cmdLineArr */
		/* call proceesExecute function */

	/* if the locationFlag is 0 */
		/* call to builtin func */
		/* free cmdLineArr */

	/* free struct data */
	free(commandData);
	return (0);
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
cmd_t *searchCmd(char *commandName)
{
	/* declare variables */
	cmd_t *commandData;
	struct stat st;

	/* initialize variables */
	commandData = malloc_checked(sizeof(cmd_t));


	 /* return a struct with number and character */

	/* check if commandName contain a forward slash */
	if (strchr(commandName, "/"))
	{
		/* do stat check on commandName */
		if (stat(commandName, &st) == 0)
		{
			/**
			 * if stat check is true, assign 2 to locationFlag
			 * assign commandData
			 * 2 means the user entered the correct path of a binary file
			 */
			commandData->cmd = commandName;
			commandData->locationFlag = 2;
		}
		else
		{
			/* else free the struct data and return NULL */
			free(commandData);
			/* set errno: no such file or directory */
			return (NULL);
		}
	}


	/*check the builtin functions for a command name match */
	if (isBuiltInCmd(commandName))
	{
		/**
		 * n will be 0 to indicate that the command is a builtin command
		 * char will be pointer to the name of the function
		 */
		commandData->cmd = commandName;
		commandData->locationFlag = 0;
		return (commandData);
	}

	if ((commandPath = searchPath(char *commandName)) != NULL)
	{
		/* check the path directories for the command */
		commandData->cmd = commandPath;
		commandData->locationFlag = 1;
		return (commandData);
	}

	/* if non of the above worked */
	/* set errno: no such file or directory */
	/* free struct data */
	free(commandData);
	return(NULL);
}



/**
 *
 *
 *
 */
int (*isBuiltInCmd(char *commandName))(void)
{
	builtInFunc_t func[] = {
		{"env", env},
		{"exit", exit},
		{NULL, NULL}
	};

	size_t idx;

	idx = 0;

	while (func[idx].cmdName)
	{
		if (strcmp(commandName, func[idx].cmdName) == 0)
			return (func[idx].builtInCmd);
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
	list_t *head;
	char *cmdDirPath;


	/* initialize variables */
	head = NULL;
	cmdDirPath = NULL;


	/* search for command file in PATH directories */
	head = createPathDirList();
	cmdDirPath = locateCmdDirPath(head, commandName);
	if (cmdDirPath == NULL)
	{
		free(head);
		return (NULL);
	}

	/* free the PATH directory list */
	free(head);

	return (cmdDirPath);
}
/**
 *
 *
 *
 *
 *
 */
char *locateCmdDirPath(list_t *h, char *cmdName)
{
	/* declare variables */
	list_t *temp;
	size_t tempBufSize, bufSize, foundSig;
	char *cmdDirPath, *pathnameMem;
	struct stat st;

	/* initialize variables */
	lenCmdName = strlen(commandName);
	bufSize = 0;
	cmdDirPath = NULL;
	foundSig = 0;
	temp = h;

	while (temp != NULL && foundSig == 0)
	{
		tempBufSize = temp->n + lenCmdName + 1;
		if (bufsize == 0)
		{
			bufSize = tempBufSize;
			pathnameMem = malloc_checked(bufSize);
		}

		if (tempBufSize > bufSize)
		{
			bufsize = tempBufSize;
			pathnameMem = realloc(pathnameMem, sizeof(char) * bufSize);
		}

		cmdDirPath = strcpy(pathnameMem, temp->str);
		cmdDirPath = strcat(pathnameMem, commandName);

		/**
		 * check if command file exist in PATH directory pointed to by dirPath
		 */
		if (stat(cmdDirPath, &st) == 0)
		{
			foundSig = 1;
			return (cmdDirPath);
		}
		temp = temp->next;
	}

	if (cmdDirPath != NULL && foundSig == 0)
	{
		free(cmdDirPath);
	}

	return (NULL);
}

