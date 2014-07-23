#include"Solution.h"
//

int Solution::candy(vector<int> &ratings) {
	const int len = ratings.size();
	vector<int> &in = ratings;
	int* tag = new int[len];
	fill(tag, tag + len, 0);
	for (int i = 0; i < len-1; i++)
	{
		if (in[i] < in[i + 1])
		{
			if (tag[i] == 0)
				tag[i] = 1;
			tag[i + 1]=tag[i] + 1;
		}
	}
	for (int j = len - 1; j > 0; j--)
	{
		if (in[j] < in[j - 1])
		{
			if (tag[j] == 0)
				tag[j] = 1;
			if (tag[j - 1] == 0)
				tag[j - 1] = tag[j] + 1;
		}
	}
	for (int i = 0; i < len;i++)
	if (tag[i] == 0)
		tag[i] = 1;
	for (int i = 0; i < len-1; i++)
	{
		if (tag[i] == tag[i + 1])
		{
			if (in[i]>in[i + 1])
				tag[i]++;
			else if (in[i] < in[i + 1])
				tag[i + 1]++;
		}
	}
	for (int i = 0; i < len - 1; i++)
	{
		//if (in[i]>in[i + 1] && tag[i] <= tag[i + 1] || in[i]<in[i + 1] && tag[i] >= tag[i + 1])
		//	cout << in[i] << " " << in[i + 1] << ":" << tag[i] << " " << tag[i + 1] << endl;
		if (in[i]>in[i + 1] && tag[i] <= tag[i + 1])
		{
			tag[i] = tag[i + 1] + 1;
		}
		if (in[i]<in[i + 1] && tag[i] >= tag[i + 1])
		{
			tag[i + 1] = tag[i] + 1;
		}
		//if (in[i]>in[i - 1] && tag[i] <= tag[i - 1] || in[i]<in[i - 1] && tag[i] >= tag[i - 1])
		//	cout << in[i] << " " << in[i - 1] << ":" << tag[i] << " " << tag[i - 1] << endl;
	}
	int ans = 0;
	for (int i = 0; i < len; i++){
		//cout << tag[i] << " ";
		ans += tag[i];
	}
	//cout << endl;


	return ans;
}