#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 41. First Missing Positive

int firstMissingPositive(int *nums, int numsSize)
{
	// int i;
	// int num, tmpNum;

	// for(i = 0; i < numsSize; i++) {
	//     num = nums[i];
	//     while(0 < num && num <= numsSize && num != nums[num - 1]) {
	//         tmpNum = nums[num - 1];
	//         nums[num - 1] = num;
	//         num = tmpNum;
	//     }
	// }

	// for(i = 0; i < numsSize; i++) {
	//     if(nums[i] != i + 1) {
	//         return i + 1;
	//     }
	// }

	// return numsSize + 1;

	int i, retNum;
	int tmpNumsSize, nextNumsSize;

	if (numsSize <= 0)
	{
		return 1;
	}

	retNum = 0;
	nextNumsSize = numsSize;
	while (1)
	{
		retNum++;

		tmpNumsSize = nextNumsSize;
		nextNumsSize = 0;

		for (i = 0; i < numsSize; i++)
		{
			if (0 < nums[i] && nums[i] <= tmpNumsSize)
			{
				nums[i]--;
				nextNumsSize++;
			}
		}

		if (nextNumsSize == 0)
		{
			break;
		}
		else if (retNum > 1 && tmpNumsSize == nextNumsSize)
		{
			retNum--;
			break;
		}
	}

	return retNum;
}

int main()
{
	return 0;
}