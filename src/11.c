#include <stdio.h>

int maxArea(int *height, int heightSize)
{
	int retMax = 0;
	int tmpArea;
	int left = 0, right = heightSize - 1;

	while (left < right)
	{
		tmpArea = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
		if (tmpArea > retMax)
		{
			retMax = tmpArea;
		}

		if (height[left] < height[right])
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	return retMax;
}

int main()
{
	return 0;
}