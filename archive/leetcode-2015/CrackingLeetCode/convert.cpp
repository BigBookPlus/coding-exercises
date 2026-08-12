#include"Solution.h"
string Solution::convert(string s, int nRows)
{
	if (nRows == 1)
		return s;
	int d = nRows * 2 - 2;
	string ret;
	for (int i = 0; i < s.length(); i += d)
	{
		ret.push_back(s[i]);
	}
	int step = 1;
	int len = s.length();
	while (step<=d/2+(d%2))
	{
		for (int i = 0; i < len; i += d)
		{
			if (i + step < (i + d) - step)
			{
				if (i + step < len)
				{
					ret.push_back(s[i + step]);
				}
				if (i + d - step < len)
				{
					ret.push_back(s[i + d - step]);
				}
			}
			else if (i + step == (i + d) - step)
			{
				if (i + step < len)
					ret.push_back(s[i + step]);
			}
		}
		step++;
	}
	return ret;
}