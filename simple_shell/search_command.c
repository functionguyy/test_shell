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
command_t *searchCommmand(char *commandName)
{
	/* declare variables */
	command_t *commandData;

	/* initialize variables */
	commandData = malloc_checked(sizeof(command_t));

	commandData->command = NULL;
	commandData->locationFlag = -1;

	/*check the builtin functions for a command name match */
	if (findCommand(commandName))
	{
		/**
		 * return a struct with number and character
		 * n will be 0 to indicate that the command is a builtin command
		 * char will be pointer to the name of the function
		 */
		commandData->command = commandName;
		commandData->locationFlag = 0;
		return (commandData);
	}

	if (strchr(commandName, "/"))
	{
		commandData->command = commandName;
		/* do a stat check on commandName*/
			/*if stat check is true, assign 1 to locationFlag */
			/* commandData->locationFlag = 1; */
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


	return (dirPath)
}
