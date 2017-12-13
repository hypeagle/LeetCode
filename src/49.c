#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 49. Group Anagrams

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ** *groupAnagrams_slow(char **strs, int strsSize, int **columnSizes, int *returnSize)
{
	char ***retValue = NULL;
	char **tmpValue = NULL;
	int *retColumnSizes = NULL;
	int retReturnSize = 0;
	int i, j, k, k1value , k2value, sLen;

	int abc1[26];
	int **flag, *flag_ext;

	if (strsSize > 0)
	{
		retValue = (char ** *)malloc(1 * sizeof(char **));
		tmpValue = (char **)malloc(1 * sizeof(char *));
		retValue[0] = tmpValue;
		tmpValue[0] = strs[0];

		retColumnSizes = (int *)malloc(1 * sizeof(int));
		retColumnSizes[0] = 1;

		retReturnSize = 1;

		flag = (int **)malloc(1 * sizeof(int *));
		flag_ext = (int *)malloc(26 * sizeof(int));
		flag[0] = flag_ext;

		memset(flag_ext, 0, 26 * sizeof(int));
		for (i = 0; strs[0][i] != '\0'; i++)
		{
			flag_ext[strs[0][i] - 'a']++;
		}

		for (i = 1; i < strsSize; i++)
		{
			memset(abc1, 0, sizeof(abc1));
			for (j = 0; strs[i][j] != '\0'; j++)
			{
				abc1[strs[i][j] - 'a']++;
			}

			for (j = 0; j < retReturnSize; j++)
			{
				for (k = 0; k < 26; k++)
				{
					if (flag[j][k] != abc1[k])
					{
						break;
					}
				}
				if (k == 26)
				{
					retValue[j] = (char **)realloc(retValue[j], (retColumnSizes[j] + 1) * sizeof(char *));
					retValue[j][retColumnSizes[j]] = strs[i];
					retColumnSizes[j]++;
					break;
				}
			}
			if (j == retReturnSize)
			{
				retValue = (char ** *)realloc(retValue, (retReturnSize + 1) * sizeof(char **));
				tmpValue = (char **)malloc(1 * sizeof(char *));
				retValue[retReturnSize] = tmpValue;
				tmpValue[0] = strs[i];

				retColumnSizes = (int *)realloc(retColumnSizes, (retReturnSize + 1) * sizeof(int));
				retColumnSizes[retReturnSize] = 1;

				flag = (int **)realloc(flag, (retReturnSize + 1) * sizeof(int *));
				flag_ext = (int *)malloc(26 * sizeof(int));
				memcpy(flag_ext, abc1, sizeof(abc1));
				flag[retReturnSize] = flag_ext;

				retReturnSize++;
			}
		}
	}

	for (i = 0; i < retReturnSize; i++)
	{
		free(flag[i]);
	}
	free(flag);

	*columnSizes = retColumnSizes;
	*returnSize = retReturnSize;
	return retValue;
}

char ** *groupAnagrams(char **strs, int strsSize, int **columnSizes, int *returnSize)
{
	int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

	char ***retValue = NULL;
	char **tmpValue = NULL;
	int *retColumnSizes = NULL;
	int retReturnSize = 0;
	int i, j, k, k1value;

	int *flag_ext;

	if (strsSize > 0)
	{
		retValue = (char ** *)malloc(1 * sizeof(char **));
		tmpValue = (char **)malloc(1 * sizeof(char *));
		retValue[0] = tmpValue;
		tmpValue[0] = strs[0];

		retColumnSizes = (int *)malloc(1 * sizeof(int));
		retColumnSizes[0] = 1;

		retReturnSize = 1;

		flag_ext = (int *)malloc(1 * sizeof(int));
		flag_ext[0] = 1;
		for (i = 0; strs[0][i] != '\0'; i++)
		{
			flag_ext[0] *= prime[strs[0][i] - 'a'];
		}

		for (i = 1; i < strsSize; i++)
		{
			k1value = 1;
			for (j = 0; strs[i][j] != '\0'; j++)
			{
				k1value *= prime[strs[i][j] - 'a'];
			}

			for (j = 0; j < retReturnSize; j++)
			{
				if (k1value == flag_ext[j])
				{
					retValue[j] = (char **)realloc(retValue[j], (retColumnSizes[j] + 1) * sizeof(char *));
					retValue[j][retColumnSizes[j]] = strs[i];
					retColumnSizes[j]++;
					break;
				}
			}
			if (j == retReturnSize)
			{
				retValue = (char ** *)realloc(retValue, (retReturnSize + 1) * sizeof(char **));
				tmpValue = (char **)malloc(1 * sizeof(char *));
				retValue[retReturnSize] = tmpValue;
				tmpValue[0] = strs[i];

				retColumnSizes = (int *)realloc(retColumnSizes, (retReturnSize + 1) * sizeof(int));
				retColumnSizes[retReturnSize] = 1;

				flag_ext = (int *)realloc(flag_ext, (retReturnSize + 1) * sizeof(int));
				flag_ext[retReturnSize] = k1value;

				retReturnSize++;
			}
		}
	}

	free(flag_ext);

	*columnSizes = retColumnSizes;
	*returnSize = retReturnSize;
	return retValue;
}

int main()
{
	return 0;
}