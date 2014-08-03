#include"Solution.h"
void Solution::flatten(TreeNode *root) {
	if (root == NULL)
		return;
	solve(root);
}
TreeNode* Solution::solve(TreeNode* root)
{
	TreeNode *l = NULL, *r = NULL;
	TreeNode *tmp = root;
	if (root->left != NULL)
		l = root->left;
	if (root->right != NULL)
		r = root->right;
	if (l != NULL)
	{
		root->left = NULL;
		root->right = l;
		//root=root->right;
		tmp = solve(l);
	}
	if (r != NULL)
	{
		tmp->right = r;
		tmp=solve(r);
	}
	return tmp;
}