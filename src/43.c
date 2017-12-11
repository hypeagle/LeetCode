#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 43. Multiply Strings

char *multiply(char *num1, char *num2)
{
	if (!num1 || !num2)
	{
		return NULL;
	}
	else if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0)
	{
		return "0";
	}

	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int len = len1 + len2 + 2;
	int i, j, remain, tmp;

	char *retNum = (char *)malloc(len + 1);
	memset(retNum, '0', len);
	retNum[len] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		remain = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			tmp = (num1[i] - '0') * (num2[j] - '0') + remain + (retNum[len1 - 1 - i + len2 - 1 - j] - '0');

			retNum[len1 - 1 - i + len2 - 1 - j] = (tmp % 10) + '0';
			remain = tmp / 10;
		}

		while (remain > 0)
		{
			tmp = remain + (retNum[len1 - 1 - i + len2 - 1 - j] - '0');

			retNum[len1 - 1 - i + len2 - 1 - j] = (tmp % 10) + '0';
			remain = tmp / 10;

			j--;
		}
	}

	for (i = len - 1; i >= 0; i--)
	{
		if (retNum[i] == '0')
		{
			retNum[i] = '\0';
		}
		else
		{
			break;
		}
	}

	len = strlen(retNum);
	for (i = 0; i < (len >> 1); i++)
	{
		char tmp = retNum[i];
		retNum[i] = retNum[len - 1 - i];
		retNum[len - 1 - i] = tmp;
	}

	return retNum;
}

int main()
{
	printf("%s\n", multiply("98", "9"));
	printf("%s\n", multiply("43240067913868426472468818427581828824635114", "86825284295"));
	return 0;
}