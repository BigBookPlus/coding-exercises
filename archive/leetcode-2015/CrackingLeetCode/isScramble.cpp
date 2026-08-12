#include"Solution.h"
bool Solution::isScramble(string s1, string s2) {

	if (s1 == s2)
		return true;

	string a = s1;
	sort(a.begin(), a.end());
	string b = s2;
	sort(b.begin(), b.end());
	if (a != b)
		return false;
	for (int mid = 1; mid < s1.size(); mid++)
	{
		string s11 = s1.substr(0, mid - 0);
		string s12 = s1.substr(mid, s1.size() - mid);
		string s21 = s2.substr(0, mid - 0);
		string s22 = s2.substr(mid, s2.size() - mid);
		string s23 = s2.substr(0, s2.size() - mid);
		string s24 = s2.substr(s2.size() - mid, mid);

		if (isScramble(s11, s21) && isScramble(s12, s22) || isScramble(s11, s24) && isScramble(s12, s23))
			return true;

	}

	return false;
}

//The function below is inefficient. 
bool Solution::judgeScramble(string &s1, string &s2, int start, int end)
{
	if (end<start)
		return false;
	string a = s1;
	if (a == s2)
		return true;
	reverse(a.begin() + start, a.begin() + end);
	cout << a << endl;
	if (a == s2)
		return true;
	int mid;// = (start + end) / 2;


	for (mid = start + 1; mid != end; mid++)
	{		
		a = s1;
		reverse(a.begin() + start, a.begin() + mid);
		reverse(a.begin() + mid, a.begin() + end);
		reverse(a.begin() + start, a.begin() + end);
		//if (a == s2)
		//	return true;
		//cout << a << endl;
		if (judgeScramble(a, s2, start, mid) || judgeScramble(a, s2, mid, end))
			return true;

		//reverse(a.begin() + start, a.begin() + end);
		a = s1;
		//if (a == s2)
		//	return true;
		//cout << a << endl;
		if (judgeScramble(a, s2, start, mid) || judgeScramble(a, s2, mid, end))
			return true;

		cout << endl;
		//if (judgeScramble(s1, s2, start, mid) || judgeScramble(s1, s2, mid, end))
		//	return true;

	}

	return false;

}