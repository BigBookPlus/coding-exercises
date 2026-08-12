#include"Solution.h"
RandomListNode* Solution::copyRandomList(RandomListNode *head) {
	if (head == NULL)
		return head;
	RandomListNode* rlpt = head;
	RandomListNode* rhead = NULL;
	RandomListNode* rethead = new RandomListNode(0);
	RandomListNode* ret = rethead;
	unordered_map<RandomListNode*, RandomListNode*> ptmap;

	while (rlpt != NULL)
	{
		rethead->next = new RandomListNode(rlpt->label);
		ptmap.insert(make_pair(rlpt, rethead->next));
		rethead = rethead->next;
		rlpt = rlpt->next;
	}

	rlpt = head;
	while (rlpt != NULL)
	{
		RandomListNode* node = rlpt->random;
		if (node != NULL)
		{
			RandomListNode* nNode = ptmap[rlpt];
			nNode->random = ptmap[node];
		}
		rlpt = rlpt->next;
	}

	return ret->next;
	//int len = 0;
	//while (rlpt != NULL)
	//{
	//	len++;
	//	rlpt = rlpt->next;
	//}
	//rlpt = head;
	//while (rlpt != NULL)
	//{
	//	RandomListNode* rltmpt = rlpt;
	//	int rlen = 0;
	//	while (rltmpt != NULL)
	//	{
	//		rlen++;
	//		rltmpt = rltmpt->random;
	//	}
	//	if (rlen == len)
	//	{
	//		rhead = rlpt;
	//		break;
	//	}
	//	rlpt = rlpt->next;
	//}
	//RandomListNode* rheadtmp = rhead;
	//RandomListNode* rethead = new RandomListNode(0);
	//RandomListNode* ret = rethead;
	//while (rheadtmp != NULL)
	//{
	//	RandomListNode* tmpNode = new RandomListNode(rheadtmp->label);
	//	tmpNode->next = rheadtmp->random;
	//	rethead->next = tmpNode;
	//	rethead = rethead->next;
	//	rheadtmp = rheadtmp->next;

	//}
	//return ret->next;
}