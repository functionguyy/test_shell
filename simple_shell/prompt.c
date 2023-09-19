#include "main.h"
/**
 * _prompt - print the shell's prompt and reads the input
 *
 * Return: returns pointer to the input string or NULL
 *
 */
char *_prompt(void)
{
	char *line_ptr;

	printf("OMSH$ ");
	fflush(stdout);

	/* build a readline function */
	line_ptr = _readLine();


	return (line_ptr);
}
/**
 * runNonInteractive - interface to execute commands passed to redirections
 *
 * Return:  always 0 on success. Always successful.
 */
/* put all the non-interactive code here */
int runNonInteractive(void)
{
	char *inputLine, **cmdLineArr;
	cmd_t *cmdData;

	inputLine = _readLine();
	if (inputLine == NULL)
		return (0);
	/* split input line and create array of words */
	cmdLineArr = parseLine(inputLine, " ");
	if (cmdLineArr == NULL)
		return (0);
	/* execute the command */
	cmdData = searchCmd(cmdLineArr[0]);
	if (cmdData == NULL)
	{
		free(cmdData);
		freeArrayOfPtr(cmdLineArr);
		return (0);
	}
	executeFunc(cmdData, cmdLineArr);

	return (0);
}
/**
 * runInteractive - interface to start up the terminal to input command after a
 * prompt
 *
 * return: always 0 on success. Alway successful.
 */

int runInteractive(void)
{
	char *inputLine, **cmdLineArr;
	cmd_t *cmdData;
	size_t cmdCount;

	cmdCount = 0;

	while (1)
	{
		cmdCount++;
		inputLine = _prompt();
		if (inputLine == NULL)
			break;
		cmdLineArr = parseLine(inputLine, " ");
		if (cmdLineArr == NULL)
			continue;
		cmdData = searchCmd(cmdLineArr[0]);
		if (cmdData == NULL)
		{
			printf("./hsh: %lu: %s: not found\n", cmdCount, cmdLineArr[0]);
			free(cmdData);
			freeArrayOfPtr(cmdLineArr);
			continue;
		}

		executeFunc(cmdData, cmdLineArr);
	}
	return (0);
}
