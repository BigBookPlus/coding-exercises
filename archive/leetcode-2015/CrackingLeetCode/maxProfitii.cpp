#include"Solution.h"
int Solution::maxProfitii(vector<int> &prices)
{
	int len = prices.size();
	if (len <= 1)
		return 0;

	vector<int> f;
	vector<int> b;
	f.assign(len, 0);
	b.assign(len, 0);
	int low, high;
	low = prices[0];
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		low = min(low, prices[i]);
		if (i>0){
			f[i] = max(f[i - 1], prices[i] - low);
			//ret = max(f[i], ret);
		}
	}
	high = prices[len - 1];
	
	for (int i = len - 1; i > -0; i--)
	{
		high = max(high, prices[i]);
		if (i < len - 1)
		{
			b[i] = max(b[i + 1], high - prices[i]);
		}
		ret = max(ret, b[i] + f[i]);
	}
	return ret;

}


	// null check
	//int len = prices.size();
	//if (len == 0) return 0;

	//vector<int> historyProfit;
	//vector<int> futureProfit;
	//historyProfit.assign(len, 0);
	//futureProfit.assign(len, 0);
	//int valley = prices[0];
	//int peak = prices[len - 1];
	//int maxProfit = 0;

	//// forward, calculate max profit until this time
	//for (int i = 0; i<len; ++i)
	//{
	//	valley = min(valley, prices[i]);
	//	if (i>0)
	//	{
	//		historyProfit[i] = max(historyProfit[i - 1], prices[i] - valley);
	//	}
	//}

	//// backward, calculate max profit from now, and the sum with history
	//for (int i = len - 1; i >= 0; --i)
	//{
	//	peak = max(peak, prices[i]);
	//	if (i<len - 1)
	//	{
	//		futureProfit[i] = max(futureProfit[i + 1], peak - prices[i]);
	//	}
	//	maxProfit = max(maxProfit, historyProfit[i] + futureProfit[i]);
	//}
	//return maxProfit;
//	if (prices.size() <= 1)
//		return 0;
//	vector<int> d = prices;
//	for (int i = 0; i < d.size() - 1; i++)
//	{
//
//		d[i] = d[i + 1] - d[i];
//		cout << d[i] << " ";
//	}
//	cout << endl;
//	//int ret = 0;
//	priority_queue<int> res;
//	cout << d[0] << " ";
//	vector<int>p=d;
//	
//	for (int i = 1; i < d.size() - 1; i++)
//	{
//		int x = max(p[i], p[i] + p[i - 1]);
//		if (x>p[i - 1])
//			p[i] = x;
//		//d[i] = x;
//			
//		cout << p[i] << " ";
//	}
//	cout << endl;
//	int idx = 0;
//	int k = 0;
//	int big = p[0];
////	vector<int> tagk;
//	for (int i = 0; i<d.size() - 2; i++)
//	{
//		if (p[i]>0 && p[i] > p[i + 1]){
//			//res.push(p[i]);
//			//tagk.push_back(i);
//			if (p[i] > big){
//				big = p[i];
//				idx = i;
//			}
//		}
//		//ret += d[i];
//	}
//	int mx = big;
//	if (p[d.size() - 2] > mx)
//	{
//		mx = p[d.size() - 2];
//		idx = d.size() - 2;
//	}
//	cout << mx << endl;
//	for (int i = idx; i >= 0; i--)
//	{
//		if (p[i]<0)
//		{
//			k = i;
//			break;
//		}	
//	}
//	vector<int>q = d;
//	for (int i = 1; i <= k; i++)
//	{
//		q[i] = max(q[i], q[i] + q[i - 1]);
//		res.push(q[i]);
//		if (i == k)
//			res.push(q[0]);
//	}
//	for (int i = idx+2; i<q.size() - 1; i++)
//	{
//		q[i] = max(q[i], q[i] + q[i - 1]);
//		res.push(q[i]);
//	}
//	//if (q[q.size() - 2] > 0)
//	//	res.push(q[q.size() - 2]);
//
//	//ret += d[d.size() - 2];
//	//if (res.size() == 1)
//	//	return res.top();
//	if (res.size() == 0)
//		return mx;
//	int mn = res.top();
//	//int mx = res.top();
//	//res.pop();
//	//int mn = res.top();
//	//res.pop();
//
//	return mn + mx>0 ? mn + mx : 0;
