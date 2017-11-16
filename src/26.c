#include <stdio.h>

// 26. Remove Duplicates from Sorted Array

int removeDuplicates(int *nums, int numsSize)
{
	int retNumsSize;
	int i;

	if (numsSize <= 0)
	{
		return 0;
	}

	retNumsSize = 1;
	for (i = 1; i < numsSize; i++)
	{
		if (nums[retNumsSize - 1] != nums[i])
		{
			nums[retNumsSize++] = nums[i];
		}
	}

	return retNumsSize;
}

int main()
{
	return 0;
}