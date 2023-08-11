#include"Solution.h"
double Solution::findMedianSortedArrays(int A[], int m, int B[], int n)
{
	int a = 0, b = 0,mx;
	for (int i = 0; i < (m + n) / 2 + ((m+n) % 2) ; i++)
	{
		if (a < m&&b < n){
			if (A[a] < B[b])
			{
				if (i == (m + n) / 2 + ((m + n) % 2) - 1)
					mx = A[a];
				a++;
			}
			else
			{
				if (i == (m + n) / 2 + ((m + n) % 2) - 1)
					mx = B[b];
				b++;
			}
		}
		else if (a < m)
		{
			if (i == (m + n) / 2 + ((m + n) % 2) - 1)
				mx = A[a];
			a++;
		}
		else if (b < n)
		{
			if (i == (m + n) / 2 + ((m + n) % 2) - 1)
				mx = B[b];
			b++;
		}
	}
	//int mx =  max(A[a], B[b]);
	if ((m + n) % 2 == 1)
		return (double)mx;
	else
	{
		int mx2;
		if (a<m&&b<n)
		 mx2=min(A[a], B[b]);
		else if (a < m)
		{
			mx2 = A[a];
		}
		else if (b < n)
		{
			mx2 = B[b];
		}

		return (double)(mx + mx2) / 2;
	}
}