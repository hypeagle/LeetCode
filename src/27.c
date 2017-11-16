#include <stdio.h>

// 27. Remove Element

int removeElement(int *nums, int numsSize, int val)
{
	int retNumsSize, tmpVal;
	int i;

	if (numsSize <= 0)
	{
		return 0;
	}

	retNumsSize = 0;
	for (i = 0; i < numsSize;)
	{
		if (val == nums[i])
		{
			tmpVal = nums[i];
			nums[i] = nums[numsSize - 1];
			nums[numsSize - 1] = tmpVal;

			numsSize--;
		}
		else
		{
			retNumsSize++;
			i++;
		}
	}

	return retNumsSize;
}

int main()
{
	return 0;
}