#include "main.h"
/**
 *
 *
 *
 *
 *
 *
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char *mem;
	ssize_t n_read, i;
	size_t bufsize, supply_count;
	int loop_sig, new_line_sig;


	bufsize = BUFSIZE;
	supply_count = 0;
	loop_sig = 1;
	new_line_sig = 0;
	mem = NULL;
	n_read = 0;
	i = 0;

	if (*lineptr == NULL && *n == 0)
	{
		mem = malloc_checked(sizeof(char) * bufsize);
		*lineptr = mem;
		*n = bufsize;
	}
	else
	{
		mem = *lineptr;
		bufsize = *n;
	}


	/* the readline function will read the line and store the characters in a
	 * buffer and return the address to the buffer then the getline function
	 * will copy the characters from the buffer used by the readline function
	 * to store the intial characters it read. While the copy is happening the
	 * count of the copied character will be maintained and checked against the
	 * total size of the getline buffer. If count of copied character has the
	 * limit of the getline buffer before the copy ends, a call to realloc is
	 * made and the pointer returned assigned to the variable that previously
	 * held the getline buffer address so the copy can pickup from where it
	 * stopped.
	 */



	while (loop_sig == 1)
	{

		if (supply_count >= bufsize)
		{
			bufsize += BUFSIZE;
			/* perform reallocation and assign new address to mem */
			mem = _realloc(mem, *n, bufsize);
			*n = bufsize;
			*lineptr = mem;
		}

		n_read = read(fd, mem, bufsize);
		if (n_read == -1)
			perror("Error reading input");

		while (i < n_read)
		{
			if (mem[i] == '\n')
			{
				printf("yes");
				mem[i] = '\0';
				new_line_sig = 1;
				loop_sig = 0;
			}
			i++;
		}

		if (new_line_sig == 0 && n_read > 0)
		{
			mem[n_read] = '\0';
			loop_sig = 0;
		}
		supply_count += n_read;
	}

	return (supply_count);
}
