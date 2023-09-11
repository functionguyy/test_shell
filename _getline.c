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
	ssize_t n_read, supply_count;
	size_t bufsize, i;


	bufsize = BUFSIZE;
	supply_count = 0;
	mem = NULL;
	i = 0;

	if (*lineptr == NULL || *n == 0)
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


	/**
	 * The read system call reads up to the new line character in the line
	 */



	while ((n_read = read(fd, mem + supply_count, bufsize - supply_count)) > 0)
	{
		supply_count += n_read;

		/* check for newline character in the newly read data */
		for (i = supply_count - n_read; i < supply_count; i++)
		{
			if (mem[i] == '\n')
			{
				mem[i] = '\0';
				return (supply_count);
			}
		}

		/* check if the buffer is full, and if so, reallocate it */
		if (supply_count >= bufsize)
		{
			bufsize += BUFSIZE;
			/* perform reallocation and assign new address to mem */
			mem = _realloc(mem, *n, bufsize);
			*n = bufsize;
			*lineptr = mem;
		}

	}

	if (n_read == 0 && supply_count == 0)
		return (-1);

	return (supply_count);
}
