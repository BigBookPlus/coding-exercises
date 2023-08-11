#include"Solution.h"
TreeNode * Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
	return buildTreeHelper(preorder, inorder, 0, 0, inorder.size() - 1);
}
TreeNode * Solution::buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int p,
	int  start, int end)
{
	if (start > end)
		return NULL;
	if (p >= preorder.size())
		return NULL;
	int x = preorder[p];
	TreeNode* node = new TreeNode(x);

	vector<int>::iterator mid = find(inorder.begin() , inorder.end(), x);
	int idx = mid - inorder.begin();//) / sizeof(int);
	int left = idx - start;
	int right = end - idx;

	if (left>0)
		node->left = buildTreeHelper(preorder, inorder, p + 1, start, idx - 1);
	if (right>0)
		node->right = buildTreeHelper(preorder, inorder, p + left + 1, idx + 1, end);

	return node;
}