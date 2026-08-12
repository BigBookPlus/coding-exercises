#include"Solution.h"
vector<string> Solution::fullJustify(vector<string> &words, int L)
{
	vector<string> ret;
	if (words.size() == 0)
		return ret;
	int pre = 0;
	int i = 0;
	int len = 0;
	vector<string> s;
	while (i <= words.size())
	{
		if (i<words.size() && len + words[i].size() + (i - pre) <= L)
		{
			s.push_back(words[i]);
			len += words[i].size();
			i++;
		}
		else
		{
			string ans;
			int n = s.size();
			int spaces = L - len;
			int even = 0;
			if (n>1)
				even = spaces / (n - 1);
			int add = spaces - even*(n - 1);
			for (int j = 0; j < s.size(); j++)
			{
				ans.append(s[j]);
				if (j != s.size() - 1){
					if (i != words.size()){
						for (int k = 0; k < even; k++)
							ans.push_back(' ');
						if (add-->0)
							ans.push_back(' ');
					}
					else
					{
						ans.push_back(' ');
					}
				}
				else if (s.size() == 1)
				{
					for (int i = 0; i<L - s[j].size(); i++)
						ans.push_back(' ');
				}
			}
			if (i == words.size())
			{
				len = ans.size();
				for (int i = 0; i < L - len; i++)
					ans.push_back(' ');
			}
			ret.push_back(ans);
			s.clear();
			pre = i;
			len = 0;
			if (i == words.size())
				break;
		}

	}

	return ret;
}