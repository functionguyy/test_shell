#ifndef MAIN_H_
#define MAIN_H_
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024

void *malloc_checked(unsigned int b);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **lineptr, size_t *n, int fd);

#endif /* MAIN_H_ */
