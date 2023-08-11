#include"Solution.h"
ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2)
{
	int len1 = 0,len2=0;
	ListNode*p1 = l1;
	ListNode*p2 = l2;
	while (p1)
	{
		len1++;
		p1 = p1->next;
	}
	while (p2)
	{
		len2++;
		p2 = p2->next;
	}
	if (len1<len2)
		swap(l1, l2);
	p1 = l1, p2 = l2;

	while (p1&&p2)
	{
		p1->val += p2->val;
		p1 = p1->next;
		p2 = p2->next;
	}
	p1 = l1;
	while (p1->next)
	{
		if (p1->val >= 10){
			p1->next->val += p1->val / 10;
			p1->val %= 10;
		}
		p1 = p1->next;
	}
	if (p1->val >= 10){
		p1->next = new ListNode(p1->val / 10);
		p1->val %= 10;
	}

	return l1;

	//int len1 = 0,len2=0;
	//ListNode*p1 = l1;
	//ListNode*p2 = l2;
	//while (p1)
	//{
	//	len1++;
	//	p1 = p1->next;
	//}
	//while (p2)
	//{
	//	len2++;
	//	p2 = p2->next;
	//}
	//if (len1<len2)
	//	swap(l1, l2);
	//p1 = l1, p2 = l2;

	//for (int i = 0; i < len1 - len2; i++)
	//	p1 = p1->next;


	//if (len1 < len2)
	//	swap(p1, p2);

	//while (p1&&p2)
	//{
	//	p1->val += p2->val;
	//	p1 = p1->next;
	//	p2 = p2->next;
	//}
	//
	//ListNode* node = new ListNode(0);
	//p1 = l1;
	//while (p1)
	//{
	//	ListNode* t = node->next;
	//	node->next = p1;
	//	p1 = p1->next;
	//	node->next->next = t;
	//}
	//p1 = node->next;
	//while (p1->next)
	//{
	//	p1->next->val += (p1->val / 10);
	//	p1->val %= 10;
	//	p1 = p1->next;
	//}
	//p1 = node->next;
	//node->next = NULL;
	//while (p1)
	//{
	//	ListNode*t = node->next;
	//	node->next = p1;
	//	p1 = p1->next;
	//	node->next->next = t;
	//}
	//if (node->next)
	//{
	//	if (node->next->val >= 10){
	//		node->val += (node->next->val / 10);
	//		node->next->val %= 10;
	//	}
	//}
	//ListNode* ans = new ListNode(0);
	//if (node->val != 0)
	//	p1= node;
	//else
	//	p1=node->next;
	//while (p1)
	//{
	//	ListNode*t = ans->next;
	//	ans->next = p1;
	//	p1 = p1->next;
	//	ans->next->next = t;
	//}
	//return ans->next;
}