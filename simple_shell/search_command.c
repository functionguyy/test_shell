#include "main.h"
/**
 *
 *
 *
 */
int executeFunc(cmd_t *commandData, char **cmdLineArr)
{
	char *cmdPath;
	/*int (*builtIn)(void);*/

	cmdPath = NULL;
	/*builtIn = NULL;*/
	/* if the locationFlag is 2 */
	if (commandData->locationFlag == 2)
		/* call processExecute function */
		processExecute(cmdLineArr[0], cmdLineArr);

	/* if the locationFlag is 1 */
	if (commandData->locationFlag == 1)
	{
		/* extract the pointer in the first index  of cmdLineArr */
		/*currentCmd = cmdLineArr[0];*/
		/* free the extracted memory space */
		/*free(currentCmd);*/
		/* now assign the pointer in the struct data to the index cmdLineArr */
		cmdPath = commandData->cmd;
		/* call proceesExecute function */
		processExecute(cmdPath, cmdLineArr);
		free(cmdPath);
	}

	/* if the locationFlag is 0 */
	if (commandData->locationFlag == 0)
	{
		/* call to builtin func */
		/*builtIn = isBuiltInCmd(commandData->cmd);*/
		/*builtIn();*/
		/* free cmdLineArr */
		freeArrayOfPtr(cmdLineArr);
	}

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
	char *cmdPath;

	/* initialize variables */
	commandData = malloc(sizeof(cmd_t));
	if (commandData == NULL)
		return (NULL);
	cmdPath = NULL;


	 /* return a struct with number and character */

	/* check if commandName contain a forward slash */
	if (strchr(commandName, '/'))
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
			return (commandData);
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
		printf("yes\n");
		commandData->cmd = commandName;
		commandData->locationFlag = 0;
		return (commandData);
	}

	/* search for command in PATH */
	cmdPath = searchPath(commandName);
	if (cmdPath != NULL)
	{
		/* check the path directories for the command */
		commandData->cmd = cmdPath;
		commandData->locationFlag = 1;
		/*free(cmdPath);*/
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
	builtInCmd_t func[] = {
		{"env", NULL},
		{"exit", NULL},
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
 * searchPath - searches the directories in the PATH enviroment variables for
 * the directory containing the binary file associated with a command
 * commandName: the name of the command whose binary is to be searched for
 *
 * Return: returns a pointer to the directory containing the binary file or NULL
 * if the file is not found.
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
		free_list(head);
		return (NULL);
	}

	/* free the PATH directory list */
	free_list(head);

	return (cmdDirPath);
}
/**
 *
 *
 *
 *
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

	while (temp != NULL && foundSig == 0)
	{
		/*tempBufSize = temp->len + lenCmdName + 2;
		if (tempBufSize > bufSize)
		{
			bufSize = tempBufSize;
			pathnameMem = realloc(pathnameMem, sizeof(char) * bufSize);
		}

		cmdDirPath = strcpy(pathnameMem, temp->str);
		if (cmdDirPath[(temp->len) - 1] != '/')
			cmdDirPath = strcat(pathnameMem, slash);
		cmdDirPath = strcat(pathnameMem, cmdName);*/
		cmdDirPath = createDirPath(temp, &pathnameMem, cmdName, bufSize);
		printf("%s\n", cmdDirPath);

		/**
		 * check if command file exist in PATH directory pointed to by dirPath
		 */
		if (stat(cmdDirPath, &st) == 0)
		{
			foundSig = 1;
			bufSize = strlen(cmdDirPath);
			pathnameMem = malloc_checked(sizeof(char) * (bufSize + 1));
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
 *
 *
 *
 *
 *
 */
list_t *createPathDirList(void)
{
	/* declare variables */
	char *pathDirToken, *envValue;
	list_t *head;

	/* initialize variables */
	head = NULL;
	envValue = strdup(_getenv("PATH"));
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
