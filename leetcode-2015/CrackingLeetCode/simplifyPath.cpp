#include"Solution.h"
string Solution::simplifyPath(string path)
{
	int pre = 0;
	int cur = 1;
	int i = 1;
	stack<string> st;
	
	while(i < path.size())
	{
		if (path[i] == '/'||i==path.size()-1)
		{
			if (i - pre>1||(i - pre==1&&i==path.size()-1&&path[i] != '/')){
				string s = path.substr(pre + 1, i - pre - (path[i] == '/' ? 1:0));
				if (s == ".")
				{
					// do nothing.
				}
				else if (s == "..")
				{
					if (!st.empty())
						st.pop();
				}
				else
				{
					st.push(s);
				}
			}
			pre = i;
		}
		i++;
	}

	if (st.empty())
		return "/";

	vector<string> ans;
	while (!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}

	string ret;
	
	for (auto it = ans.rbegin(); it != ans.rend(); it++)
	{
		ret.push_back('/');
		ret.append(*it);
	}
	
	return ret;

}