#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 34. Search for a Range

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int *retNums = (int *)malloc(2 * sizeof(int));
	int index = 0;
	int left, right, mid = 0;
	int i;

	retNums[0] = -1;
	retNums[1] = -1;
	*returnSize = 2;
	if (!nums || numsSize <= 0)
	{
		return retNums;
	}

	left = 0;
	right = numsSize - 1;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (nums[mid] == target)
		{
			break;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	if (nums[mid] == target)
	{
		for (i = mid - 1; i >= 0; i--)
		{
			if (nums[i] != target)
			{
				break;
			}
		}
		retNums[0] = i + 1;

		for (i = mid + 1; i < numsSize; i++)
		{
			if (nums[i] != target)
			{
				break;
			}
		}
		retNums[1] = i - 1;
	}

	return retNums;
}

int main()
{
	return 0;
}