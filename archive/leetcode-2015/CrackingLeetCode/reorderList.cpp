#include"Solution.h"
void Solution::reorderList(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return;
	ListNode *newHead1 = new ListNode(0);
	ListNode *newHead2 = new ListNode(0);
	newHead1->next = head;
	ListNode *l1 = head, *l2 = head->next;
	while (l1->next != NULL&&l2->next != NULL)
	{
		l1 = l1->next;
		l2 = l2->next;
		if (l2->next != NULL){
			l2 = l2->next;
		}

	}
	newHead2->next = l1->next;
	l1->next = NULL;
	//reverse newHead2;
	ListNode* index = newHead2->next;
	while (index->next != NULL)
	{
		ListNode* tmp = newHead2->next;
		newHead2->next = index->next;
		index->next = index->next->next;
		newHead2->next->next = tmp;
	}

	//index = newHead2->next;
	//while (index != NULL){
	//	cout << index->val << " ";
	//	index = index->next;
	//}
	//cout << endl;

	index = newHead1->next;
	while (newHead2->next != NULL)
	{
		ListNode *tmp = index->next;
		index->next = newHead2->next;
		newHead2->next = newHead2->next->next;
		index = index->next;
		index->next = tmp;
		index = index->next;
	}
	head = newHead1->next;
}