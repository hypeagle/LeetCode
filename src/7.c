#include <stdio.h>

// 7. Reverse Integer

int reverse(int x)
{
	int retX = 0, midX;
	int remaind;
	int tmpX = x;
	int MAX_INT = 0x7FFFFFFF;
	int MIN_INT = 0x80000000;

	if (x == MIN_INT)  // special case
	{
		return 0;
	}

	if (x < 0)
	{
		tmpX = -x;
	}

	while (1)
	{
		if (tmpX == 0)
		{
			break;
		}

		remaind = tmpX % 10;
		tmpX /= 10;

		midX = retX * 10;
		if (retX > 0 && (midX / retX) != 10)  // overflow
		{
			return 0;
		}
		retX = midX + remaind;
	}

	if (x < 0)
	{
		retX = -retX;
	}

	return retX;
}

int main()
{
	printf("%d\n", reverse(123));
	printf("%d\n", reverse(-123));
	printf("%d\n", reverse(120));
	printf("%d\n", reverse(1534236469));
	printf("%d\n", reverse(-2147483648));

	return 0;
}