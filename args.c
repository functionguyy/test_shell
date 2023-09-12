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

	i = 1;

	if (ac > 1)
	{
		/* shell operates in non-interactive mode */
		while (av[i] != NULL)
		{
			printf("%s\n", av[i]);
			i++;
		}
	}
	else
	{
		/* shell start interactive mode */
	}

	return (0);
}
