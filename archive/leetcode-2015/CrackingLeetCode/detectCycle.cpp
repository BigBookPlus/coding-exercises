#include"Solution.h"
ListNode* Solution::detectCycle(ListNode *head) {
	if (head == NULL)
		return NULL;
	ListNode *p1 = head, *p2 = head->next;
	if (p2 == NULL)
		return NULL;
	if (p2 == head)
	{
		return head;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		if (p2->next != NULL){
			if (p2->next == head)
				return head;
			p2 = p2->next;
			if (p2->next != NULL){
				if (p2->next == head)
					return head;
				p2 = p2->next;
			}
			else
				return NULL;
		}
		else
			return NULL;
	}
	p1 = head;
	ListNode* innerNode = p2;
	//cout <<"innerNode: "<< innerNode->val << endl;
	ListNode* checkNode = innerNode->next;

	int len1 = 0, len2 = 0;
	do{
		len1++;
		p2 = p2->next;
	} while (p2 != innerNode);

	//cout << len1 << endl;

	do{
		len2++;
		p1 = p1->next;
	} while (p1 != innerNode);

	p1 = (len1 > len2 ? innerNode : head);
	p2 = (len1 > len2 ? head : innerNode);
	for (int i = 0; i < abs(len1 - len2); i++)
	{
		p1 = p1->next;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;

}