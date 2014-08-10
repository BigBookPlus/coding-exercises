#include"Solution.h"
int Solution::numDecodings(string s) {
	int len = s.size();
	int *dp = new int[len];
	fill(dp, dp + len, 0);
	if (isCode(s,0,1))
		dp[0] = 1;
	for (int i = 1; i < len; i++)
	{
		if (isCode(s,i,1))
			dp[i] = dp[i - 1];
		if (i>0&& isCode(s, i - 1, 2))
			dp[i] += (i>=2?dp[i - 2]:1);
	}
	return dp[len - 1];
	//int ans = 0;
	//countDecode(s, 0, ans);
	//return ans;
}

void Solution::countDecode(string s, int start, int&ans)
{
	if (start >= s.size()){
		ans++;
		return;
	}
	for (int i = 1; i <= 2; i++)
	{
		if (isCode(s, start, i))
		{
			countDecode(s, start + i, ans);
		}
	}
}

bool Solution::isCode(string s, int start, int len)
{
	int ret = 0;
	if (len == 2 && s[start] == '0')
		return false;
	for (int i = 0; i < len; i++)
	{
		ret *= 10;
		ret += (s[start + i] - '0');
	}
	if (ret>0 && ret <= 26)
		return true;
	return false;
}
int  Solution::codeVal(string s, int start, int len)
{
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret *= 10;
		ret += (s[start + i] - '0');
	}
	return ret;
}