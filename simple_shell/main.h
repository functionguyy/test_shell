#ifndef MAIN_H_
#define MAIN_H_

/* library headers */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	size_t len;
	struct list_s *next;
} list_t;

/* macros */
#define BUFSIZE 1024

/* global variable */
extern char **environ;

/* data structure for singly-linked list */



/* functions */
void *malloc_checked(unsigned int b);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_prompt(void);
char **splitLine(char *str);
size_t list_len(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);
int processExecute(char **line_arr);
size_t print_list(const list_t *h);
void freeArrayOfPtr(char **arr);
char *_readLine(void);
ssize_t isEmptyString(char *str, char *delimiter);
char **createArrayOfLineTokens(list_t *h);
list_t *createListOfLineTokens(char *str, char *delim);
char **parseLine(char *str, char *delimiter);

#endif /* MAIN_H_ */
