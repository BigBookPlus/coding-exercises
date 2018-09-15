#include"Solution.h"
void Solution::connecti(TreeLinkNode *root) {
	if (root == NULL)
		return;
	queue<TreeLinkNode*> q;
	q.push(root);
	int level = 0;
	//vector<int> num ;
	//num.push_back(1);
	int num = 1;
	while (!q.empty())
	{
		TreeLinkNode* pre = q.front();
		q.pop();
		int count = 0;
		if (pre->left != NULL)
		{
			q.push(pre->left);
			count++;
		}

		if (pre->right != NULL)
		{
			q.push(pre->right);
			count++;
		}

		int i = 1;

		while (i<num){

			TreeLinkNode* cur = q.front();
			q.pop();

			if (cur->left != NULL)
			{
				q.push(cur->left);
				count++;
			}

			if (cur->right != NULL)
			{
				q.push(cur->right);
				count++;
			}

			pre->next = cur;
			pre = cur;
			i++;
		}
		level++;
		num = count;
		//num *= 2;
	}
}