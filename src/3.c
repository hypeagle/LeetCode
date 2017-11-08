#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3. Longest Substring Without Repeating Characters

int lengthOfLongestSubstring(char *s)
{
	int len = strlen(s);
	int i, j, retLength, tmp1, tmp2;

	char *indexCount = (char *)malloc(len + 1);
	memset(indexCount, 0x0, len  + 1);
	indexCount[0] = 1;

	for (i = 1; i < len; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (s[i] == s[j])
			{
				tmp1 = i - j;
				tmp2 = indexCount[i - 1] + 1;

				indexCount[i] = tmp1 < tmp2 ? tmp1 : tmp2;
				break;
			}
		}

		if (j == -1)
		{
			tmp1 = i - j;
			tmp2 = indexCount[i - 1] + 1;

			indexCount[i] = tmp1 < tmp2 ? tmp1 : tmp2;
		}
	}

	retLength = 0;
	for (i = 0; i < len; i ++)
	{
		if (indexCount[i] > retLength)
		{
			retLength = indexCount[i];
		}
	}

	free(indexCount);
	return retLength;
}

int main()
{
	printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
	printf("%d\n", lengthOfLongestSubstring("bbbbb"));
	printf("%d\n", lengthOfLongestSubstring("pwwkew"));

	return;
}