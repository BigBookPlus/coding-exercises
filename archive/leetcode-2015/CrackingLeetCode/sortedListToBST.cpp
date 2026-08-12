#include"Solution.h"
TreeNode* Solution::sortedListToBST(ListNode *head)
{
	if (head == NULL)
		return NULL;
	ListNode* pHead = new ListNode(0);
	pHead->next = head;
	ListNode* qHead=head;

	while (qHead->next != NULL)
	{
		pHead = pHead->next;
		qHead = qHead->next;
		if (qHead->next)
			qHead = qHead->next;
		else
			break;		
	}

	qHead = pHead->next->next;
	pHead->next->next=NULL;

	ListNode *tmp = pHead->next;
	pHead->next = NULL;

	TreeNode* node = new TreeNode(tmp->val);
	if (head!=tmp)
		node->left=sortedListToBST(head);

	node->right=sortedListToBST(qHead);

	return node;
}

