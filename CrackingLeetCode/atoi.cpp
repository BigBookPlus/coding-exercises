#include"Solution.h"
int Solution::atoi(const char *str)
{
	const char*p = str;
	bool flag = true;
	while (*p == ' ') p++;
	if (*p == '-')
	{
		flag = false;
		p++;
	}
	else if (*p == '+')
	{
		p++;
	}
	if (!*p) return 0;
	long long ret = 0;
	while (*p)
	{
		if (*p >= '0'&&*p <= '9'){
			ret *= 10;
			ret += (*p - '0');
			p++;
		}
		else 
			break;
	}
	//while (*p)
	//{
	//	if (*p != ' ')
	//		return 0;
	//	p++;
	//}
	long long max = (1 << 31)-1;
	if (ret >= max) { 
		if (!flag)
			ret = 1 << 31;
		else
			ret = (1 << 31) - 1;
	}
	if (!flag) 
		return -ret;
	return ret;
}