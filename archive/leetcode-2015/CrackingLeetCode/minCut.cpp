#include"Solution.h"
int Solution::minCut(string s)
{
	const int slen = s.length();
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

	int maxP = 0;
	for (int i = 0; i < tlen - 1; i++)
	{
		int x, y;
		int len = f[i] / 2;
		if (len>maxP)
			maxP = len;
		if (i % 2 == 1)
		{
			x = (i / 2) - len / 2;
			y = (i / 2) + len / 2;
			tag[x][y] = 1;
			while (++x <= --y)
				tag[x][y] = 1;
		}
		else if (len / 2>0)
		{
			x = (i / 2) - len / 2;
			y = (i / 2) + len / 2 - 1;
			tag[x][y] = 1;
			while (++x <= --y)
				tag[x][y] = 1;
		}
	}

	//int ans = slen-maxP+1;
	//findMin(s, tag, 0, slen, ans, 0);
	//cout << ans - 1 << endl;
	int* ans = new int[slen];
	ans[0] = 0;
	for (int i = 1; i < slen; i++)
	{
		ans[i] = i;
		for (int j = i; j >= 0; j--)
		{
			if (tag[j][i])
			{
				if (j == 0)
					ans[i] = 0;
				else
					ans[i] = min(ans[i], ans[j - 1] + 1);
			}
		}
	}
	cout << ans[slen - 1] << endl;
	return ans[slen-1];

}

void Solution::findMin(string t, int** tag, int start, int tlen, int &ans, int count)
{
	if (count >= ans)
	{
		return;
	}
	if (start == tlen && count<ans)
	{
		ans = count;
		return;
	}
	for (int i = start; i < tlen; i++)
	{
		if (tag[start][i])
		{
			findMin(t, tag, i + 1, tlen, ans, count+1);
		}
	}
}