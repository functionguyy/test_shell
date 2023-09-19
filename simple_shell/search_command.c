#include "main.h"
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
	/* free struct data */
	free(commandData);
	return(NULL);
}
