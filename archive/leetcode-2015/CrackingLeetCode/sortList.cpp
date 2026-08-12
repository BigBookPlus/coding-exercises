#include"Solution.h"
ListNode* Solution::sortList(ListNode *head) {
	if (head == NULL)
		return head;
	return mergeSort(head);
}
ListNode* Solution::merge(ListNode* l1, ListNode* l2)
{

	ListNode* head1 = new ListNode(0);
	head1->next = l1;
	ListNode* node1 = head1;
	ListNode* head2 = new ListNode(0);
	head2->next = l2;
	ListNode* node2 = head2;

	while (node1->next != NULL&&node2->next != NULL)
	{
		if (node1->next->val <= node2->next->val)
		{
			node1 = node1->next;
		}
		else{
			ListNode* tmp = node1->next;
			node1->next = node2->next;
			node2->next = node2->next->next;
			node1->next->next = tmp;
		}
	}
	if (node2->next != NULL)
	{
		node1->next = node2->next;
	}
	return head1->next;

}
ListNode* Solution::mergeSort(ListNode* list)
{
	ListNode* p1 = list;
	ListNode* p2 = list->next;
	if (p2 == NULL)
		return list;
	if (p2->next == NULL)
	{
		if (p1->val > p2->val)
			swap(p1->val, p2->val);
		return p1;
	}
	while (p1->next != NULL&&p2->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
		if (p2 != NULL)
			p2 = p2->next;
		if (p2 == NULL)
			break;
	}
	ListNode* mid = p1;
	ListNode* head1 = list;
	ListNode* head2 = p1->next;
	p1->next = NULL;

	head1 = mergeSort(head1);
	head2 = mergeSort(head2);
	ListNode*res = merge(head1, head2);
	return res;
}