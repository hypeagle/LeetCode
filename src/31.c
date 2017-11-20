#include <stdio.h>

// 31. Next Permutation

void nextPermutation(int *nums, int numsSize)
{
	int i, j, k;
	int tmpNum;

	if (!nums || numsSize < 2)
	{
		return;
	}

	for (k = numsSize - 2; k >= 0; k--)
	{
		if (nums[k + 1] > nums[k])
		{
			break;
		}
	}

	if (k < 0)
	{
		k = 0;
	}

	// printf("k = %d\n", k);

	for (i = numsSize - 1; i >= k; i--)
	{
		for (j = i - 1; j >= k; j--)
		{
			if (nums[i] > nums[j])
			{
				break;
			}
		}

		if (j >= k)
		{
			break;
		}
	}

	if (i >= 0)
	{
		tmpNum = nums[i];
		nums[i] = nums[j];
		nums[j] = tmpNum;
	}

	for (i = j + 1; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] > nums[j])
			{
				tmpNum = nums[i];
				nums[i] = nums[j];
				nums[j] = tmpNum;
			}
		}
	}
}

int main()
{
	int i;
	int nums[] = {5, 4, 7, 5, 3, 2};

	nextPermutation(nums, 6);

	for (i = 0; i < 6; i++)
	{
		printf("%d\t", nums[i]);
	}
	printf("\n");
	return 0;
}