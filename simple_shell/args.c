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
	else
	{
		while (1)
		{
			/* shell start interactive mode */
			p_return = _prompt();
			if (p_return == NULL)
				break;
			cmdLineArr = splitLine(p_return);
			if (cmdLineArr == NULL)
				perror("splitLine");
			processExecute(cmdLineArr);
		}
	}

	putchar('\n');
	return (0);
}
