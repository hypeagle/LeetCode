#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 38. Count and Say

char *countAndSay(int n)
{
	char *retStr = NULL;
	char *tmpStr = NULL;
	int i, j, count, tmpLen;

	if (n <= 0)
	{
		return retStr;
	}

	retStr = (char *)malloc(2 * sizeof(char));
	retStr[0] = '1';
	retStr[1] = '\0';
	for (i = 2; i <= n; i++)
	{
		tmpStr = retStr;
		retStr = NULL;

		j = 0;
		while (tmpStr[j] != '\0')  // it can change to 1-for
		{
			count = 1;
			j++;
			while (tmpStr[j] != '\0' && tmpStr[j] == tmpStr[j - 1])
			{
				count++;
				j++;
			}
			if (retStr == NULL)
			{
				retStr = (char *)malloc(3 * sizeof(char));
				retStr[0] = count + '0';
				retStr[1] = tmpStr[j - 1];
				retStr[2] = '\0';
			}
			else
			{
				tmpLen = strlen(retStr);
				retStr = realloc(retStr, tmpLen + 3);
				retStr[tmpLen] = count + '0';
				retStr[tmpLen + 1] = tmpStr[j - 1];
				retStr[tmpLen + 2] = '\0';
			}
			count = 0;
		}

		if (tmpStr)
		{
			free(tmpStr);
			tmpStr = NULL;
		}
	}

	if (tmpStr)
	{
		free(tmpStr);
		tmpStr = NULL;
	}
	return retStr;
}

int main()
{
	return 0;
}