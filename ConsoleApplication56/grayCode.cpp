#include"Solution.h"
vector<int> Solution::grayCode(int n) {
	vector < int > ret = {0};
	vector<int> help;
	if (n == 0)
		return ret;
	int k = 0;
	int p = 1;
	while (k < n)
	{
		help = ret;
		for (auto it = help.rbegin(); it != help.rend(); it++)
		{
			ret.push_back(*it + p);
		}
		p *= 2;
		k++;
	}
	return ret;
}