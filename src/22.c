#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 22. Generate Parentheses

void backTrack(char ***list, int *index, int open, int close, char *str, int max)
{
	if (close == max)
	{
		*list = (char **)realloc(*list, (*index + 1) * sizeof(char *));
		char *tmp = (char *)malloc(2 * max + 1);
		strcpy(tmp, str);
		(*list)[*index] = tmp;
		*index = *index + 1;
		return;
	}

	if (open < max)
	{
		int len = strlen(str);
		str[len] = '(';
		str[len + 1] = '\0';
		backTrack(list, index, open + 1, close, str, max);
		str[len] = '\0';
	}
	if (close < open)
	{
		int len = strlen(str);
		str[len] = ')';
		str[len + 1] = '\0';
		backTrack(list, index, open, close + 1, str, max);
		str[len] = '\0';
	}
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize)
{
	char **retList = NULL;
	char *str = (char *)malloc(2 * n + 1);
	str[0] = '\0';

	*returnSize = 0;
	backTrack(&retList, returnSize, 0, 0, str, n);

	free(str);
	return retList;
}

int main()
{
	int returnSize;

	generateParenthesis(3, &returnSize);
	return 0;
}