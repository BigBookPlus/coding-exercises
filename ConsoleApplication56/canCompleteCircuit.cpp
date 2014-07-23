#include"Solution.h"
int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
	int gasSum = 0;
	int costSum = 0;
	int start = 0;
	const int len = gas.size();
	int i = 0;
	int count = 0;
	while (count<len){
		gasSum += gas[i];
		costSum += cost[i];
		i++;
		i%=len;
		count++;
		while (gasSum < costSum && start < len)
		{
			gasSum -= gas[start];
			costSum -= cost[start];
			start++;
			count--;
		}
	}
	if (start == len)
		return -1;
	return start;
}