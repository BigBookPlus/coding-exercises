#include "Solution.h"
vector<string> Solution::wordBreak(string s, unordered_set<string> &dict) {
	vector<vector<int>> ret;
	vector<string> result;
	vector<int> ans;
	int slen = s.length();

	//bool dp[1000][1000];
	bool **dp = new bool*[200];
	bool *tag = new bool[200];
	fill(tag, tag + 200, true);
	for (int i = 0; i < 200; i++)
		dp[i] = new bool[200];
	vector<vector<int>> sucs;
	for (int i = 0; i < slen; i++)
		sucs.push_back(vector<int>());
	for (int i = 0; i < slen; i++){
		for (int j = i; j < slen; j++)
		{
			if (dict.find(s.substr(i, j - i + 1)) != dict.end()){
				dp[i][j] = true;
				sucs[i].push_back(j);
			}
			else
				dp[i][j] = false;
		}
	}

	//findWordBreak3(s, 0,  ans, ret, sucs);
	findWordBreak2(s, 0, ans, ret, dp, tag);
	for (int i = 0; i < ret.size(); i++)
	{
		vector<int> tmp = ret[i];
		string put;
		int start = 0;
		for (int j = 0; j < tmp.size(); j++)
		{
			put.append(s.substr(start, tmp[j] - start + 1));
			if (j != tmp.size() - 1)
				put.push_back(' ');
			start = tmp[j]+1;
		}
		result.push_back(put);
	}

	return result;
}

void Solution::findWordBreak(string s, int idx, unordered_set<string> &dict, string ans, vector<string> &ret)
{
	if (idx == s.length()){
		ret.push_back(ans);
		return;
	}
	int len = 1;
	while (idx + len <= s.length())
	{
		string tmp = s.substr(idx, len);
		unordered_set<string>::iterator it_set = dict.find(tmp);
		if (it_set != dict.end()){
			string tmp1 = ans+tmp;
			//cout << tmp << endl;
			if (idx < s.length())
				tmp1.push_back(' ');
			findWordBreak(s, idx + len, dict, tmp1, ret);
		}
		len++;
	}
}
bool Solution::findWordBreak2(string s, int idx, vector<int> &ans, vector<vector<int>> &ret, bool **dp, bool* tag)
{
	if (idx == s.length()){
		ret.push_back(ans);
		return true;
	}
	int len = 1;
	bool flag = false;
	while (idx + len <= s.length())
	{
		if (dp[idx][idx+len-1]&&tag[idx+len]){
			ans.push_back(idx + len - 1);
			if (findWordBreak2(s, idx + len, ans, ret, dp, tag) == false)
				tag[idx + len] = false;
			else
				flag = true;
			ans.pop_back();
		}
		len++;
	}
	return flag;
}
void Solution::findWordBreak3(string s, int idx, vector<int> ans, vector<vector<int>> &ret, vector<vector<int>> &sucs)
{
	if (idx == s.length()){
		ret.push_back(ans);
		cout << "got" << endl;
		return;
	}
	cout << "in" << endl;
	for (int i = 0; i < sucs[idx].size();i++)
	{
		int j = sucs[idx][i];
		vector<int> tmp = ans;
		tmp.push_back(j);
		findWordBreak3(s, j+1, tmp, ret, sucs);
	}
	cout << "out" << endl;
}

//bool Solution::wordBreak1(string s, unordered_set<string> &dict) {
//	vector<vector<int>> ret;
//	vector<string> result;
//	vector<int> ans;
//	int slen = s.length();
//
//	//bool dp[1000][1000];
//	bool **dp = new bool*[200];
//	bool *tag = new bool[200];
//	fill(tag, tag + 200, true);
//	for (int i = 0; i < 200; i++)
//		dp[i] = new bool[200];
//	vector<vector<int>> sucs;
//	for (int i = 0; i < slen; i++)
//		sucs.push_back(vector<int>());
//	for (int i = 0; i < slen; i++){
//		for (int j = i; j < slen; j++)
//		{
//			if (dict.find(s.substr(i, j - i + 1)) != dict.end()){
//				dp[i][j] = true;
//				sucs[i].push_back(j);
//			}
//			else
//				dp[i][j] = false;
//		}
//	}
//
//	//findWordBreak3(s, 0,  ans, ret, sucs);
//	return findWordBreak4(s, 0, ans, ret, dp, tag);
//
//}
//bool Solution::findWordBreak4(string s, int idx, vector<int> &ans, vector<vector<int>> &ret, bool **dp, bool* tag)
//{
//	if (idx == s.length()){
//		ret.push_back(ans);
//		return true;
//	}
//	int len = 1;
//	//bool flag = false;
//	while (idx + len <= s.length())
//	{
//		if (dp[idx][idx + len - 1] && tag[idx + len]){
//			ans.push_back(idx + len - 1);
//			if (findWordBreak4(s, idx + len, ans, ret, dp, tag) == false)
//				tag[idx + len] = false;
//			else
//				return true;
//			ans.pop_back();
//		}
//		len++;
//	}
//	return false;
//	//return flag;
//}