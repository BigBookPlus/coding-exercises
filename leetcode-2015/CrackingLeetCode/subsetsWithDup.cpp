#include"Solution.h"
vector<vector<int> > Solution::subsetsWithDup(vector<int> &S) {
	sort(S.begin(), S.end());
	vector<int> ans;
	set<vector<int>> uset;
	vector<vector<int>> ret;
	ret.push_back(ans);
	for (int i = 1; i <= S.size(); i++)
	{
		count(i, S, 0, 0, ans, uset);
	}
	for (auto it = uset.begin(); it != uset.end(); it++)
		ret.push_back(*it);
	return ret;
}

void Solution::count(int n, vector<int>&S, int step, int start, vector<int>& ans, set<vector<int>>& ret)
{
	if (step == n)
	{
		ret.insert(ans);
		return;
	}
	for (int i = start; i < S.size(); i++)
	{
		ans.push_back(S[i]);
		count(n, S, step + 1, i + 1,ans, ret);
		ans.pop_back();
	}
}