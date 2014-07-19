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
}