#include"Solution.h"

void Solution::reverseWords(string &s) {
	string s1, s2;
	stack<string> sstack;
	istringstream is(s);
	ostringstream os(s2);
	while (is >> s1)
		sstack.push(s1);

	while (!sstack.empty())
	{
		s2 += sstack.top();
		sstack.pop();
		if (sstack.size() > 0){
			s2 += " ";
		}
	}
	s = s2;
}