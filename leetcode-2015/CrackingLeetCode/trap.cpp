#include"Solution.h"
int Solution::trap(int A[], int n) {
	stack<int> st;
	int ans = 0;
	int start = 0;
	while (A[start] <= A[start + 1]) start++;
	cout <<"start\t"<< start << endl;
	int low, up;
	int i = start;
	while (i < n)
	{
		if (st.empty() || A[st.top()]>=A[i])
		{
			if (!st.empty()&&A[st.top()] == A[i])
				st.pop();
			st.push(i);
			i++;
		}
		else if (A[st.top()] < A[i])
		{
			low = A[st.top()];
			st.pop();
			if (!st.empty()){
				up = min(A[st.top()], A[i]);
				ans += (up - low)*(i - st.top() - 1);
			}
		}

	}

	return ans;
}
//for (int i = start; i < n; i++)
	//{
	//	if (st.empty() || A[st.top()]>A[i])
	//	{
	//		st.push(i);
	//	}
	//	else if (A[st.top()] < A[i])
	//	{
	//		low = A[st.top()];
	//		st.pop();
	//		
	//		if (A[i] <= A[st.top()])
	//		{
	//			up = A[i];
	//			ans+=(up - low)*(i - st.top()-1);
	//			if (A[i] < A[st.top()])
	//				st.push(i);
	//			else if (A[i] == A[st.top()]&&st.size() == 1)
	//				st.pop();
	//		}
	//		else
	//		{
	//			while (!st.empty() && A[st.top()] < A[i])
	//			{
	//				up = A[st.top()];
	//				ans += (up - low)*(i - st.top() - 1);
	//				low = up;
	//				st.pop();
	//			}
	//			//st.push(i);
	//		}
	//	}
	//}