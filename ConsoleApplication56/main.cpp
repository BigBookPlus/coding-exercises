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

	int A[4] = { 1 };
	cout << sln.singleNumber(A, 1) << endl;

	vector<int> can = { 58, 21, 72, 77, 48, 9, 38, 71, 68, 77, 82, 47, 25, 94, 89, 54, 26, 54, 54, 99, 64, 71, 76, 63, 81, 82, 60, 64, 29, 51, 87, 87, 72, 12, 16, 20, 21, 54, 43, 41, 83, 77, 41, 61, 72, 82, 15, 50, 36, 69, 49, 53, 92, 77, 16, 73, 12, 28, 37, 41, 79, 25, 80, 3, 37, 48, 23, 10, 55, 19, 51, 38, 96, 92, 99, 68, 75, 14, 18, 63, 35, 19, 68, 28, 49, 36, 53, 61, 64, 91, 2, 43, 68, 34, 46, 57, 82, 22, 67, 89 };
	cout << sln.candy(can) << endl;

}