#include <stdio.h>

// 10. Regular Expression Matching

#define bool char
#define true 1
#define false 0

bool isMatch(char *s, char *p)
{
	char *ss, *pp;
	char *tmpSS, *tmpPP;

	if (s == NULL || p == NULL)
	{
		return false;
	}

	ss = s;
	pp = p;

	while (*ss != '\0' && *pp != '\0')
	{
		if (*(pp + 1) == '*')
		{
			if (*pp == '.')
			{
				tmpSS = ss;
				tmpPP = pp + 2;
				while (*tmpSS != '\0')
				{
					if (isMatch(tmpSS, tmpPP))
					{
						return true;
					}
					tmpSS++;
				}

				if (*tmpSS == '\0' && *tmpPP != '\0')
				{
					while (*tmpPP != '\0')
					{
						if (*(tmpPP + 1) == '*')
						{
							tmpPP += 2;
						}
						else
						{
							break;
						}
					}
				}

				if (*tmpPP == '\0' && *tmpSS == '\0')
				{
					return true;
				}

				return false;
			}
			else
			{
				tmpSS = ss;
				tmpPP = pp + 2;
				while (*tmpSS != '\0' && *tmpSS == *pp)
				{
					if (isMatch(tmpSS, tmpPP))
					{
						return true;
					}
					tmpSS++;
				}

				if (*tmpSS == '\0' && *tmpPP != '\0')
				{
					while (*tmpPP != '\0')
					{
						if (*(tmpPP + 1) == '*')
						{
							tmpPP += 2;
						}
						else
						{
							break;
						}
					}
				}

				if (*tmpPP == '\0' && *tmpSS == '\0')
				{
					return true;
				}

				ss = tmpSS;
				pp += 2;
			}
		}
		else if (*pp == '.')
		{
			ss++;
			pp++;
		}
		else if (*ss == *pp)
		{
			ss++;
			pp++;
		}
		else
		{
			break;
		}
	}

	if (*ss == '\0' && *pp != '\0')
	{
		while (*pp != '\0')
		{
			if (*(pp + 1) == '*')
			{
				pp += 2;
			}
			else
			{
				break;
			}
		}
	}

	if (*ss == '\0' && *pp == '\0')
	{
		return true;
	}

	return false;
}

int main()
{
	printf("%d\n", isMatch("aa", "a"));
	printf("%d\n", isMatch("aa", "aa"));
	printf("%d\n", isMatch("aaa", "aa"));
	printf("%d\n", isMatch("aa", "a*"));
	printf("%d\n", isMatch("aa", ".*"));
	printf("%d\n", isMatch("ab", ".*"));
	printf("%d\n", isMatch("aab", "c*a*b"));
	printf("%d\n", isMatch("a", "ab*"));
	printf("%d\n", isMatch("abcaaaaaaabaabcabac", ".*ab.a.*a*a*.*b*b*"));
	return 0;
}