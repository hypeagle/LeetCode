#include <stdio.h>

// 9. Palindrome Number

#define bool char
#define true 1
#define false 0

bool isPalindrome(int x)
{
	int y = 0;
	int tmp = x;

	if (x < 0)
	{
		return false;
	}
	else if (x == 0)
	{
		return true;
	}

	while (1)
	{
		if (tmp == 0)
		{
			break;
		}

		y = y * 10 + tmp % 10;
		tmp /= 10;
	}

	if (y == x)
	{
		return true;
	}

	return false;
}

int main()
{
	return 0;
}