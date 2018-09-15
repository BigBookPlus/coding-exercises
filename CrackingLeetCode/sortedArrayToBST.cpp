#include"Solution.h"
TreeNode* Solution::sortedArrayToBST(vector<int> &num) {
	return sortedArrayToBST(num, 0, num.size() - 1);
}

TreeNode* Solution::sortedArrayToBST(vector<int> &num, int start, int end)
{
	if (end < start)
		return NULL;
	int mid = (start + end) / 2;
	TreeNode* node = new TreeNode(num[mid]);

	node->left = sortedArrayToBST(num, start, mid - 1);
	node->right = sortedArrayToBST(num, mid + 1, end);

	return node;
}