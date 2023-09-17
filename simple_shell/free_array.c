#include "main.h"
/**
 *
 *
 *
 *
 *
 */
void freeArrayOfPtr(char **arr)
{
	char **arrOfPtrs;
	size_t n;

	n = 0;
	arrOfPtrs = arr;

	while (arrOfPtrs[n] != NULL)
	{
		free(arrOfPtrs[n]);
		n++;
	}
	free(arrOfPtrs);

}
