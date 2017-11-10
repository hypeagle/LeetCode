#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 14. Longest Common Prefix

char *longestCommonPrefix(char **strs, int strsSize)
{
	if (strs == NULL || strsSize <= 0)
	{
		return "";
	}

	int firstLen = strlen(strs[0]);
	int i, j;
	char *retStr = (char *)malloc(firstLen + 1);

	for (i = 0; i < firstLen; i++)
	{
		for (j = 1; j < strsSize; j++)
		{
			if (strs[0][i] != strs[j][i])
			{
				break;
			}
		}

		if (j == strsSize)
		{
			retStr[i] = strs[0][i];
		}
		else
		{
			break;
		}
	}

	retStr[i] = '\0';
	return retStr;
}

int main()
{
	return 0;
}