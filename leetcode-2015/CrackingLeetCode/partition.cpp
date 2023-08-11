#include"Solution.h"

vector<vector<string>> Solution::partition(string s)
{
	vector<vector<string>> ret;
	vector<string>ans;

	const int slen = s.length();
	if (slen == 1)
	{
		ans.push_back(s);
		ret.push_back(ans);
		return ret;
	}
	string t;
	for (int i = 0; i < slen; i++)
	{
		t.push_back(' ');
		t.push_back(s[i]);
	}
	t.push_back(' ');
	const int tlen = t.length();
	int *f = new int[tlen+1];
	fill(f, f + tlen + 1, 1);
	int j = 0;
	int maxLen = 0;
	for (int i = 1; i < tlen; i++)
	{
		int minLen = 1;
		if (2 * j - i >= 0)
			minLen = min(f[2 * j - i], f[j] - 2 * (i - j));
		if (minLen <= 0)
			minLen = 1;
		for (int step = minLen / 2 + 1; i + step < tlen&&i - step >= 0; step++)
		{
			if (t[i + step] == t[i - step])
				minLen += 2;
			else
				break;
		}
		f[i] = minLen;
		if ((i + f[i] / 2)>maxLen)
		{
			maxLen = i + f[i] / 2;
			j = i;
		}
	}
	//for (int i = 0; i < tlen; i++)
	//{
	//	cout << f[i] / 2 << " ";
	//}
	//cout << endl;

	int **tag = new int*[slen];
	for (int i = 0; i < slen; i++){
		tag[i] = new int[slen];
		fill(tag[i], tag[i] + slen, 0);
	}

	for (int i = 0; i < tlen-1; i++)
	{
		int x, y;
		int len = f[i] / 2;
		if (i % 2 == 1)
		{
			x = (i / 2) - len / 2;
			y = (i / 2) + len / 2;
			tag[x][y] = 1;
			while (++x <= --y)
				tag[x][y] = 1;
		}
		else if (len/2>0)
		{
			x = (i / 2) - len / 2;
			y = (i / 2) + len / 2 - 1;
			tag[x][y] = 1;
			while (++x <= --y)
				tag[x][y] = 1;
		}

	}

	//for (int i = 0; i < slen; i++){
	//	for (int j = 0; j < slen; j++)
	//	{
	//		cout << tag[i][j]<<" ";
	//	}
	//	cout << endl;
	//}



	dfs(s, tag, 0, slen, ret, ans);

	for (int i = 0; i < ret.size(); i++){
		for (int j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	return ret;
}

void Solution::dfs(string t, int** tag, int start, int tlen, vector<vector<string>> &ret, vector<string> ans)
{
	if (start == tlen)
	{
		ret.push_back(ans);
		return;
	}
	for (int i = start; i < tlen; i++)
	{
		if (tag[start][i])
		{
			string s = t.substr(start, i-start+1);
			ans.push_back(s);
			dfs(t, tag, i+1, tlen,ret, ans);
			ans.pop_back();
		}
	}
}
//bool isP(string s)
//{
//	int l = s.length();
//	for (int i = 0; i < l / 2; i++)
//	{
//		if (s[i] != s[l - 1 - i])
//			return false;
//	}
//	return true;
//}