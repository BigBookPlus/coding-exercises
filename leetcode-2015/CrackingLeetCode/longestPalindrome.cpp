#include"Solution.h"
string Solution::longestPalindrome(string s)
{
	string t;
	for (int i = 0; i < s.size(); i++)
	{
		t.push_back('*');
		t.push_back(s[i]);
	}
	t.push_back('*');
	int max = 1;
	int k = 0;
	int maxLen = 0;
	int maxIdx = 0;
	int *f = new int[t.size()];
	fill(f, f + t.size(), 1);

	for (int i = 0; i < t.size(); i++)
	{
		int minLen = 1;
		minLen = min(f[2 * k - i], f[k] - 2 * (i - k));
		if (minLen <= 0)
			minLen = 1;
		int count = minLen;
		int j = minLen/2+1;
		//if (i>maxPos)
		//	maxPos = i;
		for (; i - j >= 0 && i + j < t.size(); j++)
		{
			if (t[i - j] == t[i + j]){
				count += 2;
			}
			else
				break;
		}
		f[i] = count;
		if (count/2>max/2)
		{
			maxIdx = i;
			max = count;
		}
		if (i + f[i] / 2 > maxLen)
		{
			k = i;
			maxLen = i + f[i] / 2;
		}

	}
	string res;

	for (int i = maxIdx - max / 2 + 1; i <= maxIdx + max / 2 && i<t.size(); i += 2)
		res.push_back(t[i]);

	return res;
}