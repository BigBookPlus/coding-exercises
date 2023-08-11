#include"Solution.h"
int Solution::lengthOfLongestSubstring(string s)
{
	int len = s.size();
	int *f = new int[len];
	fill(f, f + len, 0);
	int t[256];
	fill(t, t + 256, 0);
	int l = 0, r = 0;
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		if (t[s[i]] == 0)
		{
			t[s[i]]++;
		}
		else 
		{
			r = i - 1;
			if (r - l + 1>ret)
				ret = r - l + 1;
			while ( t[s[i]] == 1 && l<=i )
			{
				t[s[l]]--;
				l++;
			}
			t[s[i]] = 1;
		}
	}
	if (len - 1 - l + 1 > ret)
		ret = len - 1 - l + 1;
	return ret;
}