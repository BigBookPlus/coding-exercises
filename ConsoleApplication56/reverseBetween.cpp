#include"Solution.h"
ListNode *Solution::reverseBetween(ListNode *head, int m, int n) {
	int count = 1;
	ListNode* p1 = new ListNode(0);
	ListNode* ret = p1;
	p1->next = head;
	while (count<m)
	{
		p1 = p1->next;
		count++;
	}
	ListNode* insertPos = p1;
	ListNode* start = p1->next;

	ListNode* p3 = p1;
	while (count<n)
	{
		p3 = p3->next;
		count++;
	}

	ListNode* end = p3->next;

	ListNode* tmp = end->next;

	end->next = NULL;

	ListNode* pt = start;
	insertPos->next = NULL;
	while (pt != NULL)
	{
		ListNode* tmp = insertPos->next;
		insertPos->next = pt;
		pt = pt->next;
		insertPos->next->next = tmp;
	}
	start->next = tmp;
	return ret->next;
}