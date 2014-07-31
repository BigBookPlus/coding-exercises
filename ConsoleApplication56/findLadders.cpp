#include"Solution.h"


vector<vector<string>> Solution::findLadders(string start, string end, unordered_set<string> &dict) {

	vector<vector<string>> ret;
	vector< short >* graph = new vector< short >[dict.size() + 2];
	for (int i = 0; i < dict.size() + 2; i++)
		graph[i].reserve(50);
	//string *list = new string[dict.size() + 2];
	unordered_set<string>::const_iterator *list = new unordered_set<string>::const_iterator[dict.size() + 2];
	int idx = 0;
	int si, ti;

	for (auto it = dict.begin(); it != dict.end(); it++)
	{
		list[idx] = it;
		idx++;
	}

	si = idx;
	idx++;
	ti = idx;
	idx++;
	dict.insert(start);
	list[si] = dict.find(start);
	dict.insert(end);
	list[ti] = dict.find(end);
	int glen = idx;
	int slen = start.size();
	for (int i = 0; i < glen; i++)
	{
		for (int j = i + 1; j < glen; j++)
		{

			int count = 0;
			for (int k = 0; k < slen; k++)
			{
				if ((*list[i])[k] != (*list[j])[k])
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
	//bool *tag = new bool[glen];
	int *d = new int[glen];

	unordered_set<int>*prev = new unordered_set<int>[glen];
	//fill(tag, tag + glen, false);
	fill(d, d + glen, 1 + glen);
	d[si] = 0;

	while (!q.empty())
	{
		int a = q.front();
		q.pop();
		for (int i = 0; i < graph[a].size(); i++)
		{
			int e = graph[a][i];
			if (d[e] >= d[a] + 1){
				d[e] = d[a] + 1;
				q.push(e);
				prev[e].insert(a);

			}
			if (e == ti)
				break;
		}
		if (a == ti)
			break;
	}
	//while (!q.empty())
	//{
	//	q.pop();
	//}
	if (d[ti] == glen + 1)
		return ret;

	vector<string> sans;
	sans.push_back(*list[ti]);
	construct(prev, ret, sans, list, ti, si);

	return ret;
}

void Solution::construct(unordered_set<int>* prev, vector<vector<string>>& ret, vector<string>& ans, unordered_set<string>::const_iterator* list, int p, int si)
{
	if (p == si){
		ret.push_back(ans);
		reverse(ret[ret.size() - 1].begin(), ret[ret.size() - 1].end());
		return;
	}
	const unordered_set<int> &cu = prev[p];
	for (auto it = cu.begin(); it != cu.end(); it++)
	{
		int pp = *it;
		ans.push_back(*list[pp]);
		construct(prev, ret, ans, list, pp, si);
		ans.pop_back();
	}

}
//vector<vector<string>> Solution::findLadders(string start, string end, unordered_set<string> &dict) {
//	vector<vector<string>> ret;
//	vector< int >* graph = new vector< int >[dict.size() + 2];
//	for (int i = 0; i<dict.size() + 2; i++)
//		graph[i].reserve(50);
//	string *list = new string[dict.size() + 2];
//	int idx = 0;
//	int si, ti;
//	for (auto it = dict.begin(); it != dict.end(); it++)
//	{
//		list[idx] = *it;
//		idx++;
//	}
//
//	si = idx;
//	idx++;
//	ti = idx;
//	idx++;
//
//	list[si] = start;
//	list[ti] = end;
//	int glen = idx;
//	int slen = start.size();
//	for (int i = 0; i < glen; i++)
//	{
//		for (int j = i + 1; j < glen; j++)
//		{
//
//			int count = 0;
//			for (int k = 0; k < slen; k++)
//			{
//				if (list[i][k] != list[j][k])
//					count++;
//				if (count>1)
//					break;
//			}
//			if (count == 1){
//				graph[i].push_back(j);
//				graph[j].push_back(i);
//
//			}
//		}
//	}
//
//	//BFS Search for shortest path.
//
//	queue<int> q;
//	q.push(si);
//	bool *tag = new bool[glen];
//	int *d = new int[glen];
//	int *prev = new int[glen];
//	prev[si] = -1;
//	//memset(tag, 0, sizeof(tag));
//	fill(tag, tag + glen, false);
//	fill(d, d + glen, 1);
//	int ans = 0;
//	while (!q.empty())
//	{
//		int a = q.front();
//
//		q.pop();
//
//		for (int i = 0; i < graph[a].size(); i++)
//		{
//			int e = graph[a][i];
//			if (tag[e] == false){
//				q.push(e);
//				tag[e] = true;
//				d[e] = d[a] + 1;
//				prev[e] = a;
//			}
//		}
//	}
//	int p = prev[ti];
//	ret.push_back(vector<string>());
//	ret[0].push_back(list[ti]);
//	while (p != si)
//	{
//		ret[0].push_back(list[p]);
//		p = prev[p];
//	}
//	return ret;
//}