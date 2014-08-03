#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<sstream>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include"ListNode.h"
#include"Point.h"
#include"RandomListNode.h"
#include"UndirectedGraphNode.h"
#include"TreeNode.h"
#include"TreeLinkNodeh.h"
using namespace std;
class Solution{
private:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodemap;
public:
	void reverseWords(string &s);

	int myatoi(string &s);
	string myitoa(int i);
	int evalRPN(vector<string> &tokens);

	int maxPoints(vector<Point> &points);

	ListNode* sortList(ListNode *head);
	ListNode* merge(ListNode* l1, ListNode* l2);
	ListNode* mergeSort(ListNode* list);

	ListNode* insertionSortList(ListNode *head);

	void reorderList(ListNode *head);

	ListNode* detectCycle(ListNode *head);
	bool hasCycle(ListNode *head);

	vector<string> wordBreak(string s, unordered_set<string> &dict);
	void findWordBreak(string s, int idx, unordered_set<string> &dict, string ans, vector<string> &ret);
	bool findWordBreak1(string s, int idx, vector<int> &ans, vector<vector<int>> &ret, vector<vector<int>> &sucs, bool* tag);
	bool findWordBreak2(string s, int idx, vector<int> &ans, vector<vector<int>> &ret, bool **dp, bool *tag);
	void findWordBreak3(string s, int idx, vector<int> ans, vector<vector<int>> &ret, vector<vector<int>> &sucs);

	bool wordBreak1(string s, unordered_set<string> &dict);
	bool findWordBreak4(string s, int idx, vector<vector<int>> &sucs, bool* tag);

	RandomListNode* copyRandomList(RandomListNode *head);

	int singleNumber(int A[], int n);

	int candy(vector<int> &ratings);

	int canCompleteCircuit(vector<int> &gas, vector<int> &cost);

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);

	vector<vector<string>> partition(string s);
	void dfs(string t, int** tag, int start, int tlen, vector<vector<string>> &ret, vector<string> ans);

	int minCut(string s);
	void findMin(string t, int** tag, int start, int tlen, int &ans, int count);

	void solve(vector<vector<char>> &board);//Surrounded Regions
	bool findTag(vector<vector<char>> &board, int x, int y, int m, int n, char num);
	
	int sumNumbers(TreeNode *root);
	void calc(TreeNode* node, int num, int *ans);

	int longestConsecutive(vector<int> &num);

	int ladderLength(string start, string end, unordered_set<string> &dict);

	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict);
	void construct(unordered_set<int>* prev, vector<vector<string>>& ret, vector<string>& ans, unordered_set<string>::const_iterator* list, int p, int si);

	bool isPalindrome(string s);

	int maxPathSum(TreeNode *root);
	int calc(TreeNode *root, int& ans);

	int maxProfit(vector<int> &prices);

	int maxProfiti(vector<int> &prices);

	int maxProfitii(vector<int> &prices);

	int minimumTotal(vector<vector<int> > &triangle);

	void connect(TreeLinkNode *root);
	void connecti(TreeLinkNode *root);

	void flatten(TreeNode *root);
	TreeNode* solve(TreeNode* root);
};