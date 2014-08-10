#include"Solution.h"
int Solution::maximalRectangle(vector<vector<char> > &matrix) {
	int m = matrix.size();
	int n = 0;
	if (m > 0)
		n = matrix[0].size();
	else
		return 0;
	if (n == 0)
		return 0;
	int *h = new int[n + 1];
	fill(h, h + n, 0);

	int max = 0;
	for (int i = 0; i < m; i++)
	{
		//int j = 0;
		stack<int> s;
		for (int j = 0; j < n+1 ;j++)
		{
			if (j < n){
				if (matrix[i][j] == '1')
					h[j]++;
				else
					h[j] = 0;
			}
			if (s.empty() || h[s.top()] <= h[j])
			{
				s.push(j);
			}
			else{
				while (!s.empty()&&h[s.top()]>h[j] )
				{
					int idx = s.top();
					s.pop();
					int area = h[idx] * (s.empty() ? j : (j - s.top() - 1));
					if (area > max)
						max = area;
				}
				s.push(j);
			}
		}
	}
	return max;
}