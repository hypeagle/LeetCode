#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 47. Permutations II

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void permute_ext(int *nums, int numsSize, int *returnSize, char *flag, int *nums_ext, int currentSize, int ***retNums)
{
	if (numsSize == currentSize)
	{
		if (*returnSize == 0)
		{
			*retNums = (int **)malloc(sizeof(int *));
		}
		else
		{
			*retNums = (int **)realloc(*retNums, (*returnSize + 1) * sizeof(int *));
		}

		int *numExt = (int *)malloc(numsSize * sizeof(int));
		memcpy(numExt, nums_ext, numsSize * sizeof(int));

		(*retNums)[*returnSize] = numExt;
		*returnSize = (*returnSize) + 1;
	}
	else
	{
		int i;
		for (i = 0; i < numsSize; i++)
		{
			if (!(i > 0 && flag[i - 1] == 1 && nums[i] == nums[i - 1]))
			{
				if (flag[i] == 1)
				{
					flag[i] = 0;
					nums_ext[currentSize] = nums[i];
					permute_ext(nums, numsSize, returnSize, flag, nums_ext, currentSize + 1, retNums);
					flag[i] = 1;
				}
			}
		}
	}
}

int **permuteUnique(int *nums, int numsSize, int *returnSize)
{
	int **retNums;
	int i, j, tmpValue;

	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] > nums[j])
			{
				tmpValue = nums[i];
				nums[i] = nums[j];
				nums[j] = tmpValue;
			}
		}
	}

	*returnSize = 0;

	char *flag = (char *)malloc(numsSize);
	memset(flag, 0x1, numsSize);

	int *nums_ext = (int *)malloc(numsSize * sizeof(int));
	for (i = 0; i < numsSize; i++)
	{
		if (!(i > 0 && nums[i] == nums[i - 1]))
		{
			flag[i] = 0;
			nums_ext[0] = nums[i];
			permute_ext(nums, numsSize, returnSize, flag, nums_ext, 1, &retNums);
			flag[i] = 1;
		}
	}

	free(flag);
	free(nums_ext);

	return retNums;
}

int main()
{
	return 0;
}