#include"Solution.h"
bool Solution::isMatch2(const char* s, const char *p)
{	const char *ts=s, *tp=p;
	int lens = strlen(ts);
	int lenp = strlen(tp);
	if (*(ts + lens - 1) != *(tp + lenp - 1) && *(tp + lenp - 1) != '.'&&*(tp + lenp - 1) != '*') return false;
	if (*s == 0 && *p == 0) return true;

	else if ((*s == *p || *p == '.') && *s) 
	{
		if (*(p + 1) == '*')
			return isMatch2(s, p + 1) || isMatch2(s + 1, p + 1);
		else 
			return isMatch2(s + 1, p + 1); 
	}
	else if (*s != *p)
	{
		if (*p == '*')
		{
			while (*s&&(*s==*(p-1)||*(p-1)=='.'))
			{
				if (isMatch2(s, p+1))
					return true;
				++s;
			}
			return isMatch2(s, p + 1);
		}
		else
		{
			if (*p == 0) return false;
			else if (*(p + 1) == '*')
				return isMatch2(s, p + 2);
			else
				return false;
		}
	}
}