#include"Solution.h"
int Solution::singleNumber(int A[], int n) {
	int mask = 0x00000001;
	int ret = 0;
	for (int i = 0; i < 31; i++)
	{
		
		//cout << "mask" << mask << endl;
		int tmp = 0;
		for (int j = 0; j < n; j++)
		{
			if (A[j] & (mask<<i))
			{
				//cout << "mask " << mask << endl;
				tmp++;
			}
		}
		if (tmp % 3)
		{
			//cout << "tmp " << tmp << endl;
			ret += (mask<<i);
			//cout <<"ret"<< ret << endl;
		}
	}
	return ret;
}