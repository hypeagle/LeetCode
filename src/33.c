#include <stdio.h>

// 33. Search in Rotated Sorted Array

int search(int *nums, int numsSize, int target)
{
	int left, right, mid;
	int leftOne, rightOne, leftTwo, rightTwo;
	if (numsSize <= 0)
	{
		return -1;
	}
	else if (numsSize == 1 && nums[0] == target)
	{
		return 0;
	}

	left = 0;
	right = numsSize - 1;
	while (left < right)
	{
		mid = (left + right) >> 1;
		if (nums[left] > nums[mid])
		{
			right = mid - 1;
			if (nums[left] <= nums[right])
			{
				mid = right;
				break;
			}
		}
		else if (nums[right] < nums[mid])
		{
			left = mid + 1;
			if (nums[left] <= nums[right])
			{
				break;
			}
		}
		else
		{
			break;
		}
	}

	leftOne = 0;
	rightOne = mid;
	leftTwo = mid + 1;
	rightTwo = numsSize - 1;

	while (leftOne <= rightOne)
	{
		mid = (leftOne + rightOne) >> 1;
		if (target == nums[mid])
		{
			return mid;
		}
		else if (target > nums[mid])
		{
			leftOne = mid + 1;
		}
		else
		{
			rightOne = mid - 1;
		}
	}

	while (leftTwo <= rightTwo)
	{
		mid = (leftTwo + rightTwo) >> 1;
		if (target == nums[mid])
		{
			return mid;
		}
		else if (target > nums[mid])
		{
			leftTwo = mid + 1;
		}
		else
		{
			rightTwo = mid - 1;
		}
	}

	return -1;
}

int main()
{
	int num[] = {1, 3, 5};
	printf("%d\n", search(num, 3, 3));
	return 0;
}