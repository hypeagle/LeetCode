#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 39. Combination Sum


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum(int *candidates, int candidatesSize, int target, int **columnSizes, int *returnSize)
{
	int **retNumbers = NULL, **retNextNumbers;
	int *retColumnSizes = NULL, *retNextColumnSizes;
	int retReturnSize = 0, retNextReturnSize;
	int i, j, k;

	for (i = 0; i < candidatesSize; i++)
	{
		if (candidates[i] < target)
		{
			retNextNumbers = combinationSum(&candidates[i], candidatesSize - i, target - candidates[i], &retNextColumnSizes, &retNextReturnSize);
			if (retNextReturnSize > 0)
			{
				if (retNumbers)
				{
					retNumbers = (int **)realloc(retNumbers, (retReturnSize + retNextReturnSize) * sizeof(int *));
					retColumnSizes = (int *)realloc(retColumnSizes, (retReturnSize + retNextReturnSize) * sizeof(int));
				}
				else
				{
					retNumbers = (int **)malloc((retReturnSize + retNextReturnSize) * sizeof(int *));
					retColumnSizes = (int *)malloc((retReturnSize + retNextReturnSize) * sizeof(int));
				}
				for (j = 0; j < retNextReturnSize; j++)
				{
					retNumbers[retReturnSize + j] = (int *)malloc((retNextColumnSizes[j] + 1) * sizeof(int));
					retNumbers[retReturnSize + j][0] = candidates[i];
					retColumnSizes[retReturnSize + j] = retNextColumnSizes[j] + 1;
					for (k = 0; k < retNextColumnSizes[j]; k++)
					{
						retNumbers[retReturnSize + j][k + 1] = retNextNumbers[j][k];
					}
					free(retNextNumbers[j]);
				}
				free(retNextColumnSizes);
				free(retNextNumbers);

				retReturnSize += retNextReturnSize;
			}
		}
		else if (candidates[i] == target)
		{
			retNumbers = (int **)realloc(retNumbers, (retReturnSize + 1) * sizeof(int *));
			retNumbers[retReturnSize] = (int *)malloc(sizeof(int));
			retNumbers[retReturnSize][0] = candidates[i];

			retColumnSizes = (int *)realloc(retColumnSizes, (retReturnSize + 1) * sizeof(int));
			retColumnSizes[retReturnSize] = 1;

			retReturnSize += 1;
		}
	}

	*columnSizes = retColumnSizes;
	*returnSize = retReturnSize;
	return retNumbers;
}

int main()
{
	return 0;
}