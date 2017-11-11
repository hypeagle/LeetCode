#include <stdio.h>
#include <stdlib.h>

// 15. 3Sum

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize)
{
	if (numsSize < 3)
	{
		*returnSize = 0;
		return NULL;
	}

	int len = (numsSize * (numsSize - 1) * (numsSize - 2)) / (3 * 2 * 1);
	int **retNums = (int **)malloc(len * sizeof(int *));
	int *tmpNums = NULL;
	int index, tmp;
	int i, j, k;
	int left, right;

	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] > nums[j])
			{
				index = nums[i];
				nums[i] = nums[j];
				nums[j] = index;
			}
		}
	}

	index = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (tmpNums && nums[i] == tmpNums[0])
		{
			continue;
		}

		for (j = i + 1; j < numsSize; j++)
		{
			if (tmpNums && nums[i] == tmpNums[0] && nums[j] == tmpNums[1])
			{
				continue;
			}

			tmp = 0 - nums[i] - nums[j];
			left = j + 1;
			right = numsSize;
			k = left;
			while (left < right)
			{
				k = (left + right) >> 1;
				if (nums[k] > tmp)
				{
					right = k;
				}
				else if (nums[k] < tmp)
				{
					left = k + 1;
				}
				else
				{
					break;
				}
			}

			if (j < k && k < numsSize)
			{
				if (tmpNums && nums[i] == tmpNums[0] && nums[j] == tmpNums[1] && nums[k] == tmpNums[2])
				{
				}
				else if (tmp ==  nums[k])
				{
					tmpNums = (int *)malloc(3 * sizeof(int));
					tmpNums[0] = nums[i];
					tmpNums[1] = nums[j];
					tmpNums[2] = nums[k];

					retNums[index++] = tmpNums;
				}
			}
		}
	}

	*returnSize = index;
	return retNums;
}

int main()
{
	return 0;
}