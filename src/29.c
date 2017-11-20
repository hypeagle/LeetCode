#include <stdio.h>

#define MAX_INT 0x7FFFFFFF

int divide(int dividend, int divisor)
{
	unsigned int uDividend, uDivisor, uTmpDivisor;
	unsigned int isNeg;
	unsigned int retFactor, retTmpFactor;
	int retX;

	if (dividend == 0)
	{
		return 0;
	}
	else if (divisor == 0)
	{
		return 0;
	}
	else if (dividend < 0 && divisor > 0)
	{
		isNeg = 1;
	}
	else if (dividend > 0 && divisor < 0)
	{
		isNeg = 1;
	}
	else
	{
		isNeg = 0;
	}

	if (dividend == -2147483648)
	{
		uDividend = 2147483648;
	}
	else
	{
		uDividend = abs(dividend);
	}
	if (divisor == -2147483648)
	{
		uDivisor = 2147483648;
	}
	else
	{
		uDivisor = abs(divisor);
	}

	if (uDivisor == 1)
	{
		retFactor = uDividend;
	}
	else
	{
		retFactor = 0;

		while (uDividend >= uDivisor)
		{
			uTmpDivisor = uDivisor;
			retTmpFactor = 1;

			while (uTmpDivisor < 2147483648 && uDividend > (uTmpDivisor << 1))
			{
				retTmpFactor <<= 1;
				uTmpDivisor <<= 1;
			}

			uDividend -= uTmpDivisor;
			retFactor += retTmpFactor;
		}
	}

	if (isNeg == 1)
	{
		if (retFactor > 2147483648)
		{
			retX = -2147483648;
		}
		else
		{
			retX = -retFactor;
		}
	}
	else
	{
		if (retFactor >= 2147483648)
		{
			retX = 2147483647;
		}
		else
		{
			retX = retFactor;
		}
	}

	return retX;
}

int main()
{
	printf("%d\n", divide(-2147483648, 2));
	printf("%d\n", divide(-2147483648, -2147483648));
	return 0;
}