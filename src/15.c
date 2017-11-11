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

	int count = (numsSize * (numsSize - 1) * (numsSize - 2)) / (3 * 2 * 1);
	int **retNums = (int **)malloc(count * sizeof(int *));
	int *tmpNums = NULL;
	int i, j, k, left, right, sum, index;

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
	for (i = 0; i < numsSize - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
		{
			break;
		}
		if (nums[i] + nums[numsSize - 1] + nums[numsSize - 2] < 0)
		{
			continue;
		}

		for (j = i + 1; j < numsSize - 1; j++)
		{
			if ((j > i + 1) && (nums[j] == nums[j - 1]))
			{
				continue;
			}
			if (nums[i] + nums[j] + nums[j + 1]  > 0)
			{
				break;
			}
			if (nums[i] + nums[j] + nums[numsSize - 1] < 0)
			{
				continue;
			}

			left = j + 1;
			right = numsSize;
			while (left < right)
			{
				k = (left + right) >> 1;
				sum = nums[i] + nums[j] + nums[k];
				if (sum < 0)
				{
					left = k + 1;
				}
				else if (sum > 0)
				{
					right = k;
				}
				else
				{
					tmpNums = (int *)malloc(3 * sizeof(int));
					tmpNums[0] = nums[i];
					tmpNums[1] = nums[j];
					tmpNums[2] = nums[k];
					retNums[index++] = tmpNums;

					break;
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