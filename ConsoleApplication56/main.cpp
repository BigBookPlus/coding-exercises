#include<iostream>
#include"Solution.h"
using namespace std;

int main()
{
	ListNode* list = new ListNode(0);
	ListNode* head = list;
	for (int i = 0; i < 1; i++)
	{
		ListNode *node = new ListNode(i + 1);
		list->next = node;
		list = list->next;
	}
	//list->next = head->next;
	Solution sln;
	cout << sln.detectCycle(head) << endl;
	cout << sln.hasCycle(head) << endl;

	string s = "a";//"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";// ;
  //"catsanddog";//"aaaaaaa";//	
	unordered_set<string> dict = { "a" };// { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" }; //{"cat", "cats", "and", "sand", "dog"};//;// = { "aaa", "aaaa" };//
	vector<string> ans = sln.wordBreak(s, dict);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	cout << sln.wordBreak1(s, dict) << endl;

}