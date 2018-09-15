#include"Solution.h"
bool Solution::hasCycle(ListNode *head) {
	if (head == NULL)
		return false;
	ListNode *p1 = head, *p2 = head->next;
	if (p2 == NULL)
		return false;
	if (p2 == head)
	{
		return true;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		if (p2->next != NULL){
			if (p2->next == head)
				return true;
			p2 = p2->next;
			if (p2->next != NULL){
				if (p2->next == head)
					return true;
				p2 = p2->next;
			}
			else
				return false;
		}
		else
			return false;
	}
	return true;
}