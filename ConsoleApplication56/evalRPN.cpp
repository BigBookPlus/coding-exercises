#include"Solution.h"
int Solution::myatoi(string &s)
{
	int start = 0;
	if (s[0] == '-')
		start++;
	int ret = 0;
	for (int i = start; i < s.size(); i++)
	{
		ret *= 10;
		ret += (s[i] - '0');
	}
	if (start)
		ret = -ret;
	return ret;
}
string Solution::myitoa(int i)
{
	string ret;
	int ii = i;
	if (i < 0) i = -i;
	while (i)
	{
		int t = i % 10;
		char c = '0' + t;
		ret.push_back(c);
		i /= 10;
	}
	if (ii < 0)
		ret.push_back('-');
	reverse(ret.begin(), ret.end());
	return ret;
}
int Solution::evalRPN(vector<string> &tokens) {
	stack<string> sstack;
	if (tokens.size() < 2)
		return myatoi(tokens[0]);
	int i = 2;
	sstack.push(tokens[0]);
	sstack.push(tokens[1]);
	while (!sstack.empty())
	{
		if (i >= tokens.size())
			break;
		string str = tokens[i++];
		if ((str[0]<'0' || str[0]>'9') && str.size() == 1)
		{
			string str1 = sstack.top();
			sstack.pop();
			int i2 = myatoi(str1);
			string str2 = sstack.top();
			sstack.pop();
			int i1 = myatoi(str2);
			switch (str[0])
			{
			case '+':
				sstack.push(myitoa(i1 + i2));
				break;
			case '-':
				sstack.push(myitoa(i1 - i2));
				break;
			case '*':
				sstack.push(myitoa(i1 * i2));
				break;
			case '/':
				sstack.push(myitoa(i1 / i2));
				break;
			}
		}
		else
		{
			sstack.push(str);
		}
	}
	return myatoi(sstack.top());
}