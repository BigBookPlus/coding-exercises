#include"Solution.h"
string Solution::multiply(string num1, string num2) {
	int m = num1.size();
	int n = num2.size();
	vector<int> ret(m + n, 0);
	string rets;
	vector<int> n1,n2;
	for (int i = 0; i < num1.size(); i++)
		n1.push_back(num1[i] - '0');
	for (int i = 0; i < num2.size(); i++)
		n2.push_back(num2[i] - '0');
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ret[i + j] += (n1[i] * n2[j]);
		}
	}
	for (int i = 1; i < ret.size(); i++)
	{
		if (ret[i - 1] >= 10){
			ret[i] += (ret[i - 1] / 10);
			ret[i - 1] %= 10;
		}
	}
	int start = ret.size() - 1;
	while (ret[start] == 0) start--;
	cout << start <<ret[start]<< endl;
	while (start){
		char ch = ret[start] + '0';
		rets.push_back(ch);
		start--;
	}
	return rets;
}