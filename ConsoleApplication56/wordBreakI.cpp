#include"Solution.h"
bool Solution::wordBreak1(string s, unordered_set<string> &dict) {
	int slen = s.length();

	bool *tag = new bool[slen];
	fill(tag, tag + slen + 1, true);

	vector<vector<int>> sucs;
	for (int i = 0; i < slen; i++)
		sucs.push_back(vector<int>());

	for (int i = 0; i < slen; i++){
		for (int j = i; j < slen; j++)
		{
			if (dict.find(s.substr(i, j - i + 1)) != dict.end())
				sucs[i].push_back(j);
			
		}
	}

	return findWordBreak4(s, 0, sucs, tag);
}
bool Solution::findWordBreak4(string s, int idx, vector<vector<int>> &sucs, bool* tag)
{
	if (idx == s.length()){
		return true;
	}
	for (int i = 0; i < sucs[idx].size();i++)
	{
		int j = sucs[idx][i];
		if ( tag[j+1]){
			if (findWordBreak4(s, j+1, sucs, tag) )
				return true;
			else
				tag[j+1] = false;
		}
	}
	return false;
}