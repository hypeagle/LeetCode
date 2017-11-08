#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 5. Longest Palindromic Substring

char *longestPalindrome(char *s)
{
	char *retS;
	int len = strlen(s);
	char pLen[1010][1010] = {0};
	int i, j;
	int maxLen, begin, end, tmpLen;

	maxLen = 1;
	begin = 0;
	end = 0;
	for (i = 0; i < len; i++)
	{
		pLen[i][i] = 1;
		if (s[i] == s[i + 1])
		{
			pLen[i][i + 1] = 1;
			if (maxLen < 2)
			{
				maxLen = 2;
				begin = i;
				end = i + 1;
			}
		}
		else
		{
			pLen[i][i + 1] = 0;
		}
	}


	for (j = 2; j < len; j++)
	{
		for (i = 0; i < j - 1; i++)
		{
			if (s[i] == s[j])
			{
				pLen[i][j] = pLen[i + 1][j - 1];

				if (pLen[i][j] == 1)
				{
					tmpLen = j - i + 1;
					if (tmpLen > maxLen)
					{
						maxLen = tmpLen;
						begin = i;
						end = j;
					}
				}
			}
			else
			{
				pLen[i][j] = 0;
			}
		}
	}

	retS = (char *)malloc(maxLen + 1);
	memcpy(retS, s + begin, maxLen);
	retS[maxLen] = '\0';

	return retS;
}

int main()
{
	return 0;
}