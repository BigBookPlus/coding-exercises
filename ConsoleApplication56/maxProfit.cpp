#include"Solution.h"
int Solution::maxProfit(vector<int> &prices)
{
	if (prices.size() <= 1)
		return 0;
	vector<int> d = prices;
	for (int i = 0; i < d.size() - 1; i++)
	{
		d[i] = d[i + 1] - d[i];
	}
	int ret = d[0];
	for (int i = 1; i < d.size() - 1; i++)
	{
		d[i] = max(d[i], d[i] + d[i - 1]);
		if (d[i]>ret)
			ret = d[i];
	}
	return ret>0 ? ret : 0;
}