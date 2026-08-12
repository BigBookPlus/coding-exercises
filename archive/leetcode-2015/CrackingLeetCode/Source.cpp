#include"Solution.h"

vector<int> Solution::twoSum(vector<int> &numbers, int target)
{
	vector<pair<int, int>> List;
	vector<int> ret;
	for (int i = 0; i < numbers.size(); i++)
	{
		List.push_back(make_pair(numbers[i], i));
	}
	sort(List.begin(), List.end());
	int l = 0, r = numbers.size() - 1;
	while (l < r)
	{
		int t = List[l].first + List[r].first;
		if (t< target)
		{
			l++;
		}
		else if (t > target)
		{
			r--;
		}
		else
		{
			ret.push_back(List[l].second);
			ret.push_back(List[r].second);
			break;
		}
	}
	return ret;
}