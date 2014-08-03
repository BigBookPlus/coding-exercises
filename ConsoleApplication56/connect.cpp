#include"Solution.h"
void Solution::connect(TreeLinkNode *root) {
	if (root == NULL)
		return;
	queue<TreeLinkNode*> q;
	q.push(root);
	int level = 1;
	int num = 1;
	while (!q.empty())
	{			
		TreeLinkNode* pre=q.front();
		q.pop();
		if (pre->left != NULL)
			q.push(pre->left);
		if (pre->right != NULL)
			q.push(pre->right);
		int i = 1;
		while (i<num){

			TreeLinkNode* cur = q.front();
			q.pop();

			if (cur->left != NULL)
				q.push(cur->left);
			if (cur->right != NULL)
				q.push(cur->right);
			pre->next = cur;
			pre=cur ;
			i++;
		}
		level++;
		num *= 2;
	}
}