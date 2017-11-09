#include <stdio.h>
#include <string.h>

// 8. String to Integer (atoi)

int myAtoi(char *str)
{
	int retIntX;
	unsigned int retInt = 0, midInt, tmpInt, isNeg = 0;
	int len, i;

	if (str == NULL)
	{
		return 0;
	}

	len = strlen(str);

	i = 0;

	// trim pre-space
	for (; i < len; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			continue;
		}
		else
		{
			break;
		}
	}

	if (str[i] == '-')
	{
		i = i + 1;
		isNeg = 1;
	}
	else if (str[i] == '+')
	{
		i = i + 1;
		isNeg = 0;
	}

	for (; i < len; i++)
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			tmpInt = str[i] - '0';

			midInt = retInt * 10;
			if (retInt > 0 && (midInt / retInt) != 10)  // overflow
			{
				retInt = 2147483648;
				break;
			}

			retInt = midInt + tmpInt;
		}
		else
		{
			break;
		}
	}

	if (isNeg == 1)
	{
		if (retInt > 2147483648)
		{
			retIntX = -2147483648;
		}
		else
		{
			retIntX = -retInt;
		}
	}
	else
	{
		if (retInt >= 2147483648)
		{
			retIntX = 2147483647;
		}
		else
		{
			retIntX = retInt;
		}
	}

	return retIntX;
}

int main()
{
	printf("%d\n", myAtoi("2147483648"));

	return 0;
}