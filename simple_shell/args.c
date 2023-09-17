#include "main.h"
/**
 *
 * main - program that prints all the command line arguments passed to it
 * without using ac
 * @ac: count of the command line arguments passed to the program
 * @av: NULL terminated array of strings
 */
int main(int ac, char **av)
{
	size_t i;
	char *p_return, **cmdLineArr;

	i = 1;
	p_return = NULL;


	/* command line arguments */
	if (ac > 1)
	{
		if (ac != 2)
		{
			dprintf(STDERR_FILENO, "Usage: %s command name\n", av[0]);
			exit(EXIT_FAILURE);
		}
		/* shell operates in non-interactive mode */
		while (av[i] != NULL)
		{
			printf("%s\n", av[i]);
			i++;
		}
	}

	/* mode switching */
	if (isatty(STDIN_FILENO) == 0 && errno == ENOTTY)
	{
		/* Non-interactive mode */
		/* skip spaces or empty strings*/
		/* get line */
		p_return = _readLine();
		if (p_return == NULL)
			return (0);
		/* split line and create array of words */
		cmdLineArr = splitLine(p_return);
		/* execute the command */
		processExecute(cmdLineArr);
	}
	else
	{
		/* interactive mode */
		while (1)
		{
			/* shell start interactive mode */
			p_return = _prompt();
			if (p_return == NULL)
				return (0);
			cmdLineArr = parseLine(p_return, " ");
			if (cmdLineArr == NULL)
				continue;
			/* search command */
				/* if search return NULL */
				/* print error */
				/*continue */
			processExecute(cmdLineArr);
		}
	}

	/*putchar('\n');*/
	return (0);
}
