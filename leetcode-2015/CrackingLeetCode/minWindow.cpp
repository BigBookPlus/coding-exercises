#include"Solution.h"
string Solution::minWindow(string S, string T) {
	int lens = S.size();
	int lent = T.size();
	int hf[256] = { 0 };
	int nf[256] = { 0 };
	for (int i = 0; i < lent; i++)
		nf[T[i]]++;
	int count = 0;
	int l = 0, r = 0;

	int as = 0, an = lens;
	for (; r < lens; r++)
	{
		if (nf[S[r]] == 0) continue;
		hf[S[r]]++;
		if (hf[S[r]] <= nf[S[r]])
		{
			count++;
		}

		if (count == lent)
		{
			while (nf[S[l]]==0 || hf[S[l]]>nf[S[l]]) 
			{
				if(hf[S[l]]>nf[S[l]])
					hf[S[l]]--; 
				l++; 
			}
			if (r - l + 1 < an)
			{
				an = r - l + 1;
				as = l;
			}
		}	

		
	}
	if (count != lent)
		return  "";
	return S.substr(as, an);


}