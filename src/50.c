#include <stdio.h>


// 50. Pow(x, n)

double myPow(double x, int n)
{
	double retValue = 1, tmpValue;
	int i;
	unsigned int un;
	unsigned int tmp;

	if (n == -2147483648)
	{
		un = 2147483648;
	}
	else
	{
		un = abs(n);
	}

	while (un > 0)
	{
		tmpValue = x;
		tmp = 1;
		while (tmp < 2147483648 && un > (tmp << 1))
		{
			tmp <<= 1;
			tmpValue *= tmpValue;
		}
		un -= tmp;
		retValue *= tmpValue;
	}

	if (n < 0)
	{
		retValue = 1.0 / retValue;
	}

	return retValue;
}

int main()
{
	return 0;
}