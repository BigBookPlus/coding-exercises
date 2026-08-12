#include"Solution.h"
int Solution::maxPathSum(TreeNode *root) {
	int ans=-(1<<30);
	calc(root, ans);
	return ans;
}

int Solution::calc(TreeNode *root, int& ans)
{
//	cout << root->val << ": ";

	int a=-(1<<30), b=-(1<<30);
	if (root->left != NULL)
	{
		a = calc(root->left, ans);
		ans = max(a, ans);
//		cout << "a:"<< a << " ";
	}
	if (root->right != NULL)
	{
		b = calc(root->right, ans);
		ans = max(b, ans);
//		cout << "b:"<< b << " ";
	}
	if (root->left == NULL&&root->right == NULL){
		ans=max(ans,root->val);
//		cout << "leaf:" << root->val << " ";
		return root->val;
	}
	int sum = -(1 << 30);
	if (root->left != NULL&&root->right != NULL){
		sum = a + b + root->val;
		ans = max(ans, sum);
//		cout << "sum:" << sum << " ";
	}
		
	ans=max(ans,max(max(a, b) + root->val, root->val));
//	cout << "tail:" << max(a, b) + root->val << endl;
	return max(max(a, b) + root->val, root->val);
}