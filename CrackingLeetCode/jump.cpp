#include"Solution.h"
int Solution::jump(int A[], int n) {
	int *dp = new int[n];
	fill(dp, dp + n, 0);
	int l = 0;//r=A[0];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(dp[0], 0 + A[0]));
	for (int i = 1; i<n; i++)
	{
		while (q.top().second < i)	q.pop();
		int mn = q.top().first;
		dp[i] = mn + 1;
		q.push(make_pair(dp[i], i + A[i]));
	}
	return dp[n - 1];
}