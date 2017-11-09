#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 6. ZigZag Conversion

char *convert(char *s, int numRows)
{
	int len = strlen(s);
	char *retS = (char *)malloc(len + 1);
	int firstCount = 2 * numRows - 2;
	int i, j, index, tmp;

	if (numRows == 1)  // special case
	{
		memcpy(retS, s, len);
	}
	else
	{
		index = 0;
		for (j = 0; j < len; j += firstCount)
		{
			retS[index++] = s[j];
		}

		for (i = 1; i < numRows; i++)
		{
			for (j = i; j < len; j += firstCount)
			{
				retS[index++] = s[j];
				
				tmp = j + (firstCount - 2 * i);
				if (tmp != j && tmp < len)
				{
					retS[index++] = s[tmp];
				}
			}
		}
	}

	retS[len] = '\0';
	return retS;
}

int main()
{
	printf("%s\n", convert("PAYPALISHIRING", 3));
	printf("%s\n", convert("A", 1));

	return 0;
}