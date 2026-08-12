#include "Solution.h"
int Solution::maxPoints(vector<Point> &points) {
	if (points.size() == 0)
		return 0;
	map<double, int> hmap;
	double index[1000];
	const double eps = 0.000001;
	const int M = 1000000;
	const double INF = 1000000000;
	int max = 0;
	for (int i = 0; i < points.size(); i++)
	{
		int k = 0;
		int self = 0;
		for (int j = 0; j < points.size(); j++)
		{
			if (j == i)
				continue;/**/
			if (points[j].y == points[i].y && points[j].x == points[i].x){
				self++;
				index[k++] = 2 * INF + points[j].x * 10 + points[j].y;
				hmap[index[k]] = 0;
				continue;
			}
			if (points[j].y != points[i].y && points[j].x == points[i].x)
			{
				hmap[INF + points[j].x]++;
				index[k++] = INF + points[j].x;
				continue;
			}
			double slide = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
			slide *= M;
			slide = (int)slide;
			slide = (double)slide / M;
			hmap[slide]++;
			index[k++] = slide;
		}
		for (int j = 0; j < k; j++)
		{
			int tmax = hmap[index[j]] + hmap[index[j] + eps] + hmap[index[j] - eps] + self;
			if (tmax>max)
				max = tmax;
		}
		hmap.clear();
	}
	return max + 1;
}