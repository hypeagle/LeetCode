#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 28. Implement strStr()

// http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
// http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html

void getNext(char *needle, int *next)
{
	int i, k;

	next[0] = 0;

	for (i = 1; needle[i] != '\0'; i++)
	{
		next[i] = 0;

		k = i - 1;
		while (k >= 0)
		{
			if (needle[i] == needle[next[k]])
			{
				next[i] = next[k] + 1;
				break;
			}
			else
			{
				k = next[k] - 1;
			}
		}
	}
}

int strStr(char *haystack, char *needle)
{
	if (!haystack || !needle)
	{
		return -1;
	}

	int haystackLen = strlen(haystack);
	int needldLen = strlen(needle);

	if (haystackLen < needldLen)
	{
		return -1;
	}
	else if (needldLen == 0)
	{
		return 0;
	}
	else if (haystack == 0)
	{
		return -1;
	}

	int *next = (int *)malloc(needldLen * sizeof(int));
	getNext(needle, next);

	int i = 0, j = 0;
	while (i < haystackLen && j < needldLen)
	{
		if (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j == 0)
			{
				i++;
			}
			else
			{
				j = next[j - 1];
			}
		}
	}

	free(next);

	if (j == needldLen)
	{
		return i - needldLen;
	}

	return -1;
}

int main()
{
	printf("%d\n", strStr("hello", "ll"));
	printf("%d\n", strStr("aaaaa", "bba"));
	printf("%d\n", strStr("mississippi", "issipi"));
	printf("%d\n", strStr("mississippi", "issip"));

	return 0;
}