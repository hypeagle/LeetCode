#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 20. Valid Parentheses

#define bool char
#define true 1
#define false 0


bool isValid(char *s)
{
	int len = strlen(s);
	char *as = (char *)malloc(len + 1);
	int index = -1, i = 0;

	for (i = 0; i < len; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			index++;
			as[index] = s[i];
		}
		else if (s[i] == ')')
		{
			if (index >= 0 && as[index] == '(')
			{
				index--;
			}
			else
			{
				break;
			}
		}
		else if (s[i] == '}')
		{
			if (index >= 0 && as[index] == '{')
			{
				index--;
			}
			else
			{
				break;
			}
		}
		else if (s[i] == ']')
		{
			if (index >= 0 && as[index] == '[')
			{
				index--;
			}
			else
			{
				break;
			}
		}
	}

	if (index == -1 && i == len)
	{
		return true;
	}

	return false;
}

int main()
{
	return 0;
}