#include"Solution.h"
int Solution::ladderLength(string start, string end, unordered_set<string> &dict)
{
	vector< int >* graph = new vector< int >[dict.size() + 2];
	for (int i = 0; i<dict.size() + 2; i++)
		graph[i].reserve(50);
	string *list = new string[dict.size() + 2];
	int idx = 0;
	int si, ti;
	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		list[idx] = *it;
		idx++;
	}

	si = idx;
	idx++;
	ti = idx;
	idx++;

	list[si] = start;
	list[ti] = end;
	int glen = idx;
	int slen = start.size();
	for (int i = 0; i < glen; i++)
	{
		for (int j = i + 1; j < glen; j++)
		{

			int count = 0;
			for (int k = 0; k < slen; k++)
			{
				if (list[i][k] != list[j][k])
					count++;
				if (count>1)
					break;
			}
			if (count == 1){
				graph[i].push_back(j);
				graph[j].push_back(i);

			}
		}
	}

	//BFS Search for shortest path.

	queue<int> q;
	q.push(si);
	bool *tag = new bool[glen];
	int *d = new int[glen];
	//memset(tag, 0, sizeof(tag));
	fill(tag, tag + glen, false);
	fill(d, d + glen, 1);
	int ans = 0;
	while (!q.empty())
	{
		int a = q.front();

		q.pop();

		for (int i = 0; i < graph[a].size(); i++)
		{
			int e = graph[a][i];
			if (tag[e] == false){
				q.push(e);
				tag[e] = true;
				d[e] = d[a] + 1;
				if (e == ti)
					return d[e];
			}
		}
	}
	if (d[ti]>1)
		return d[ti];
	return 0;
}