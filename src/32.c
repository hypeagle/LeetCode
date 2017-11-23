#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 32. Longest Valid Parentheses

int longestValidParentheses(char *s)
{
	int retMax = 0, tmpMax;

	int len = strlen(s);
	int *as = (int *)malloc((len + 1) * sizeof(int));
	char *tmps = (char *)malloc(len + 1);
	int index = -1, i = 0, j;

	strcpy(tmps, s);

	index = -1;
	for (i = 0; i < len; i++)
	{
		if (tmps[i] == '(')
		{
			index++;
			as[index] = i;
		}
		else if (tmps[i] == ')')
		{
			if (index >= 0 && tmps[as[index]] == '(')
			{
				index--;
			}
			else
			{
				for (j = 0; j <= index; j++)
				{
					tmps[as[j]] = ' ';
				}
				tmps[i] = ' ';
				index = -1;
			}
		}
	}
	for (j = 0; j <= index; j++)
	{
		tmps[as[j]] = ' ';
	}

	index = -1;
	tmpMax = 0;
	for (i = 0; i < len; i++)
	{
		if (tmps[i] == '(')
		{
			index++;
			as[index] = i;
		}
		else if (tmps[i] == ')')
		{
			if (index >= 0 && tmps[as[index]] == '(')
			{
				index--;
				tmpMax += 2;
			}
			else
			{
				index = -1;
				if (tmpMax > retMax)
				{
					retMax = tmpMax;
				}
				tmpMax = 0;
			}
		}
		else
		{
			index = 0;
			if (tmpMax > retMax)
			{
				retMax = tmpMax;
			}
			tmpMax = 0;
		}
	}

	if (tmpMax > retMax)
	{
		retMax = tmpMax;
	}

	free(as);
	free(tmps);
	return retMax;
}

int main()
{
	printf("%d\n",
	       longestValidParentheses("())(())(()(((((())()())()())()((()(((()()))())(((()()(((())())))()()))))(()))))))(((((((())))(())(())(()()((()))))))()((())))))(())))))("));
	return 0;
}