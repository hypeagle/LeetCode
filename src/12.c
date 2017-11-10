#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 12. Integer to Roman

char *intToRoman(int num)
{
	char *retRomanNum = (char *)malloc(100);
	memset(retRomanNum, 0, 100);

	int tmpNum = num;
	int index = 0;

	while (tmpNum > 0)
	{
		if (tmpNum >= 1000)
		{
			retRomanNum[index++] = 'M';
			tmpNum -= 1000;
		}
		else if (tmpNum >= 900)
		{
			retRomanNum[index++] = 'C';
			retRomanNum[index++] = 'M';
			tmpNum -= 900;
		}
		else if (tmpNum >= 500)
		{
			retRomanNum[index++] = 'D';
			tmpNum -= 500;
		}
		else if (tmpNum >= 400)
		{
			retRomanNum[index++] = 'C';
			retRomanNum[index++] = 'D';
			tmpNum -= 400;
		}
		else if (tmpNum >= 100)
		{
			retRomanNum[index++] = 'C';
			tmpNum -= 100;
		}
		else if (tmpNum >= 90)
		{
			retRomanNum[index++] = 'X';
			retRomanNum[index++] = 'C';
			tmpNum -= 90;
		}
		else if (tmpNum >= 50)
		{
			retRomanNum[index++] = 'L';
			tmpNum -= 50;
		}
		else if (tmpNum >= 40)
		{
			retRomanNum[index++] = 'X';
			retRomanNum[index++] = 'L';
			tmpNum -= 40;
		}
		else if (tmpNum >= 10)
		{
			retRomanNum[index++] = 'X';
			tmpNum -= 10;
		}
		else if (tmpNum >= 9)
		{
			retRomanNum[index++] = 'I';
			retRomanNum[index++] = 'X';
			tmpNum -= 9;
		}
		else if (tmpNum >= 5)
		{
			retRomanNum[index++] = 'V';
			tmpNum -= 5;
		}
		else if (tmpNum >= 4)
		{
			retRomanNum[index++] = 'I';
			retRomanNum[index++] = 'V';
			tmpNum -= 4;
		}
		else if (tmpNum >= 1)
		{
			retRomanNum[index++] = 'I';
			tmpNum -= 1;
		}
	}

	return retRomanNum;
}

int main()
{
	printf("%s\n", intToRoman(1));
	printf("%s\n", intToRoman(3));
	printf("%s\n", intToRoman(4));
	printf("%s\n", intToRoman(5));
	printf("%s\n", intToRoman(8));
	printf("%s\n", intToRoman(9));
	printf("%s\n", intToRoman(10));
	printf("%s\n", intToRoman(1666));
	printf("%s\n", intToRoman(1970));
	return 0;
}