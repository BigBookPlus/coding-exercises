#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<sstream>
#include<map>

#include"ListNode.h"
#include"Point.h"

using namespace std;
class Solution{
public:
	void reverseWords(string &s);

	int myatoi(string &s);
	string myitoa(int i);
	int evalRPN(vector<string> &tokens);

	int maxPoints(vector<Point> &points);

	ListNode *sortList(ListNode *head);
	ListNode* merge(ListNode* l1, ListNode* l2);
	ListNode* mergeSort(ListNode* list);

	ListNode *insertionSortList(ListNode *head);

	void reorderList(ListNode *head);

	ListNode *detectCycle(ListNode *head);
	bool hasCycle(ListNode *head);

	
};