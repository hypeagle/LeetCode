#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int **fourSum(int *nums, int numsSize, int target, int *returnSize)
{
	if (numsSize < 4)
	{
		*returnSize = 0;
		return NULL;
	}

	int count = (numsSize * (numsSize - 1) * (numsSize - 2) * (numsSize - 3)) / (4 * 3 * 2 * 1);
	int **retNums = (int **)malloc(count * sizeof(int *));
	int *tmpNums = NULL;
	int i, j, left, right, sum, index;

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
	for (i = 0; i < numsSize - 3; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
		{
			break;
		}
		if (nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] < target)
		{
			continue;
		}

		for (j = i + 1; j < numsSize - 2; j++)
		{
			if ((j > i + 1) && (nums[j] == nums[j - 1]))
			{
				continue;
			}
			if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
			{
				break;
			}
			if (nums[i] + nums[j] + nums[numsSize - 1] + nums[numsSize - 2] < target)
			{
				continue;
			}

			left = j + 1;
			right = numsSize - 1;
			while (left < right)
			{
				sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum < target)
				{
					left++;
				}
				else if (sum > target)
				{
					right--;
				}
				else
				{
					tmpNums = (int *)malloc(4 * sizeof(int));
					tmpNums[0] = nums[i];
					tmpNums[1] = nums[j];
					tmpNums[2] = nums[left];
					tmpNums[3] = nums[right];
					retNums[index++] = tmpNums;

					do
					{
						left++;
					}
					while (nums[left] == nums[left - 1] && left < right);
					do
					{
						right--;
					}
					while (nums[right] == nums[right + 1] && left < right);
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