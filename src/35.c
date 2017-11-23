#include <stdio.h>

// 35. Search Insert Position

int searchInsert(int *nums, int numsSize, int target)
{
	int left, right, mid;

	if (!nums || numsSize <= 0)
	{
		return 0;
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
		else if (nums[mid] > target && ((mid - 1) >= 0 && nums[mid - 1] < target))
		{
			break;
		}
		else if (nums[mid] > target && mid == 0)
		{
			break;
		}
		else if (nums[mid] < target && ((mid + 1) < numsSize && nums[mid + 1] > target))
		{
			mid = mid  + 1;
			break;
		}
		else if (nums[mid] < target && (mid + 1) == numsSize)
		{
			mid = mid  + 1;
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

	return mid;
}

int main()
{
	return 0;
}