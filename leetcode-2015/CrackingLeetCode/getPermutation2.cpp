#include"Solution.h"
string Solution::getPermutation2(int n, int k) {
	string str;
	string ret;
	vector<int> num;
	for (int i = 1; i <= n; i++)
		str.push_back('0' + i);
	int f = 1;
	int i = 0;
	while (f <= k-1)
	{
		i++;
		f *= i;
	}
	if (i) { f /= i; }
	else i = 1;
	for (int j = 0; j< n  - i; j++)
		num.push_back(0);
	int t = k - 1;
	while (i > 0)
	{
		num.push_back(t / f );
		t %= f;
		i--;
		if (i)
		f /= i;
	}
	//num.push_back('0');

	for (int j = 0; j < num.size(); j++)
	{
		ret.push_back(str[num[j]]);
		
		str.erase(num[j],1);
	}

	return ret;


}