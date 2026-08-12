#include"Solution.h"
int Solution::maxProfiti(vector<int> &prices)
{
	if (prices.size() <= 1)
		return 0;
	vector<int> d = prices;
	for (int i = 0; i < d.size() - 1; i++)
	{

		d[i] = d[i + 1] - d[i];
		cout << d[i] << " ";
	}
	cout << endl;
	int ret = 0;

	cout << d[0] << " ";
	for (int i = 1; i < d.size() - 1; i++)
	{

		int x = max(d[i], d[i] + d[i - 1]);
		if (x>d[i - 1])
			d[i] = x;
		cout << d[i] << " ";
	}
	cout << endl;
	for (int i = 0; i<d.size() - 2; i++)
	{
		if (d[i]>0 && d[i]>d[i + 1])
			ret += d[i];
	}
	if (d[d.size() - 2] > 0)
		ret += d[d.size() - 2];
	return ret>0 ? ret : 0;
}