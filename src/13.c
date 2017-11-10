#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 13. Roman to Integer

int romanToInt(char *s)
{
	int retNum = 0;
	int len = strlen(s);
	int i;

	for (i = 0; i < len; i ++)
	{
		if (s[i] == 'M')
		{
			retNum += 1000;
		}
		else if (s[i] == 'D')
		{
			retNum += 500;
		}
		else if (s[i] == 'C')
		{
			if (s[i + 1] == 'M')
			{
				retNum += 900;
				i++;
			}
			else if (s[i + 1] == 'D')
			{
				retNum += 400;
				i++;
			}
			else
			{
				retNum += 100;
			}
		}
		else if (s[i] == 'L')
		{
			retNum += 50;
		}
		else if (s[i] == 'X')
		{
			if (s[i + 1] == 'C')
			{
				retNum += 90;
				i++;
			}
			else if (s[i + 1] == 'L')
			{
				retNum += 40;
				i++;
			}
			else
			{
				retNum += 10;
			}
		}
		else if (s[i] == 'V')
		{
			retNum += 5;
		}
		else if (s[i] == 'I')
		{
			if (s[i + 1] == 'X')
			{
				retNum += 9;
				i++;
			}
			else if (s[i + 1] == 'V')
			{
				retNum += 4;
				i++;
			}
			else
			{
				retNum += 1;
			}
		}
	}

	return retNum;

}

int main()
{
	return 0;
}