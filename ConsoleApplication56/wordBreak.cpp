#include "Solution.h"
vector<string> Solution::wordBreak(string s, unordered_set<string> &dict) {
	vector<string> ret;
	string ans;
	findWordBreak(s, 0, dict, ans, ret);
	return ret;
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