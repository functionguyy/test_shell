#include "main.h"
/**
 * executeCmd - executes a command
 * @commandData: pointer to data structure containing info about a command
 * @cmdLineArr: arguments passed in input for the command
 *
 * Return: returns 0 on success. Always successful
 */
int executeCmd(cmd_t *commandData, char **cmdLineArr)
{
	char *cmdPath;
	int (*builtIn)(void);

	cmdPath = NULL;
	builtIn = NULL;

	/* if the locationFlag is 2, command path was passed as direct input*/
	if (commandData->locationFlag == 2)
		/* call processExecute function */
		processExecute(cmdLineArr[0], cmdLineArr);

	/* if the locationFlag is 1, the command path was found in PATH */
	if (commandData->locationFlag == 1)
	{
		/* assign the found path */
		cmdPath = commandData->cmd;
		/* call proceesExecute function */
		processExecute(cmdPath, cmdLineArr);
		free(cmdPath);
	}

	/* if the locationFlag is 0 */
	if (commandData->locationFlag == 0)
	{
		/* call to builtin func */
		builtIn = isBuiltInCmd(commandData->cmd);
		builtIn();
		/* free cmdLineArr */
		freeArrayOfPtr(cmdLineArr);
	}

	/* free struct data */
	free(commandData);
	return (0);
}

