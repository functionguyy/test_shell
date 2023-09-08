#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
	ssize_t nRead, nWrite;
	char buf[1024];
	int i, new_line_sig;


	nRead = 0;
	i = 0;
	new_line_sig = 0;


	printf("$ ");
	fflush(stdout);


	nRead = read(STDIN_FILENO, buf, 1024);
	if (nRead == -1)
		perror("Error reading input ");


	/**
	 * when Enter used to signal end of file in input replace the added
	 * newline character with a null byte
	 */
	while (i < nRead)
	{
		/* replace the new line character with a null byte */
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			new_line_sig = 1;
		}
		i++;
	}

	/* executes when Ctrl+D is used to signal end of file in input */
	if (new_line_sig == 0 && nRead > 0)
	{
		/* null terminate the read input */
		buf[nRead] = '\0';
		putchar('\n');
	}


	nWrite = write(STDOUT_FILENO, buf, nRead);

	if (nWrite == -1 || nWrite < nRead)
		return (0);

	putchar('\n');

	return (0);
}
