#include"Solution.h"
int Solution::largestRectangleArea(vector<int> &height) {
	stack<int> s;
	int i = 0;
	height.push_back(0);
	int len = height.size();
	int max = 0;
	while (i < len)
	{
		if (s.empty() || height[s.top()] <= height[i])
		{
			s.push(i++);
		}
		else
		{
			int idx = s.top();
			s.pop();
			int area = height[idx] * (s.empty() ? i : (i - s.top() - 1));
			if (area > max)
				max = area;
		}
	}
	return max;
}