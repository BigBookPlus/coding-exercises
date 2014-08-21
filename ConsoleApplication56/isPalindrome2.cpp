#include"Solution.h"
bool Solution::isPalindrome(int x)
{
	int k = x;
	int sum = 0;
	while (sum <= k)
	{
		int t = k % 10;
		
		sum *= 10;
		sum += t;
		if (sum == k)
			return true;

		k /= 10;

	}
	return false;
}