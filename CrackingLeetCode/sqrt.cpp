#include"Solution.h"
int Solution::sqrt(int x) {
	if (x <= 1)
		return x;
	long long n = x;
	long long mid;
	long long l = 0, r = n;
	mid = (l + r) / 2;
	while (!(mid*mid <= n && (mid + 1)*(mid + 1)>n))
	{
		if (mid*mid<n)
		{
			l = mid + 1;
		}
		else if (mid*mid>n)
		{
			r = mid - 1;
		}
		else
		{
			return mid;
		}
		mid = (l + r) / 2;
	}
	return mid;
}