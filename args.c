#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}

	return (0);
}
