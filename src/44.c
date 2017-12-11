#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 44. Wildcard Matching

#define bool char
#define true 1
#define false 0


bool isMatch(char *s, char *p)
{
	char *string = s;
	char *wild = p;

	char *cp, *mp;

	while ( ( *string ) && ( *wild != '*' ) )
	{
		if ( ( *wild != *string ) && ( *wild != '?' ) )
		{
			return false;
		}

		wild++;
		string++;
	}

	while ( *string )
	{
		if ( *wild == '*' )
		{
			if ( !*++wild )
			{
				return true;
			}

			mp = wild;
			cp = string + 1;
		}
		else if ( ( *wild == *string ) || ( *wild == '?' ) )
		{
			wild++;
			string++;
		}
		else
		{
			wild = mp;
			string = cp++;
		}
	}

	while ( *wild == '*' )
	{
		wild++;
	}

	return !*wild;
}

int main()
{
	printf("%d\n", isMatch("aab", "c*a*b"));
	printf("%d\n",
	       isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
	               "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
	return 0;
}