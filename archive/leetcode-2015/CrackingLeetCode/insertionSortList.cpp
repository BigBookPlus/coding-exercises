#include"Solution.h"
ListNode* Solution::insertionSortList(ListNode *head) {
	if (head == NULL)
		return head;
	ListNode *newHead = new ListNode(0);
	newHead->next = head;
	ListNode *indexNode = head;
	ListNode *startNode = newHead;
	while (indexNode->next != NULL){
		while (startNode->next != indexNode->next)
		{
			if (startNode->next->val >= indexNode->next->val)
			{
				ListNode* tmp = startNode->next;
				startNode->next = indexNode->next;
				indexNode->next = indexNode->next->next;
				startNode->next->next = tmp;
				break;
			}
			startNode = startNode->next;
		}
		if (startNode->next == indexNode->next)
			indexNode = indexNode->next;
		startNode = newHead;
	}
	return newHead->next;
}