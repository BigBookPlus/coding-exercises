#include"Solution.h"

vector<vector<int> > Solution::levelOrderBottom(TreeNode *root) {
	vector<vector<int>> ret;
	if (root == NULL)
		return ret;

	int num = 1;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		int i = 0;
		int count = 0;
		vector<int>ans;
		while (i < num)
		{
			TreeNode* p = q.front();
			q.pop();
			ans.push_back(p->val);
			if (p->left){
				q.push(p->left);
				count++;
			}
			if (p->right)
			{
				q.push(p->right);
				count++;
			}
			i++;
		}
		num = count;
		ret.push_back(ans);
		ans.clear();
	}
	reverse(ret.begin(), ret.end());
	return ret;
}