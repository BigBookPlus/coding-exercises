#include"Solution.h"
bool Solution::isPalindrome(string s) {
	string ss;
	for (int i = 0; i<s.size(); i++)
	{
		if (s[i] >= 'a'&&s[i] <= 'z' || s[i] >= 'A'&&s[i] <= 'Z' || s[i] >= '0'&&s[i] <= '9')
			ss.push_back(s[i]);
	}
	for (int i = 0; i<ss.size(); i++)
	{
		if (ss[i] >= 'A'&&ss[i] <= 'Z')
			ss[i] += ('a' - 'A');
	}
	bool flag = true;
	for (int i = 0; i<ss.size() / 2; i++)
	{
		if (ss[i] != ss[ss.size() - 1 - i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}