#include <stdio.h>
#include <unistd.h>
/**
 *
 * main - program prints the PID of its parent process.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_ppid;

	/* print pid of parent process */
	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}
