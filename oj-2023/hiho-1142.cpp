#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-5;
double p[4];
double x, y;
double func(double x)
{
    double ret=0;
    for(int i=2;i>=0;i--)
        ret = x*ret+p[i];
    return ret;
}

double dist(double _x)
{
    double _y = func(_x);
    double dist = sqrt((_y-y)*(_y-y)+(_x-x)*(_x-x));
    return dist;
}

int main()
{
    for(int i=2;i>=0;--i)
    {
        cin>>p[i];
    }
    cin>>x>>y;
    double a=p[0], b=p[1], c=p[2];
    double offset = fabs(x-(-b/a/2));
    double l = x-200;
    double r = x+ 200;
    while(r-l>eps)
    {
        double mid1 = l+(r-l)/3;
        double mid2 = l+(r-l)*2/3;
        double v1 = dist(mid1);
        double v2 = dist(mid2);
        if(v1<v2)
        {
            r=mid2;
        }
        else
        {
            l=mid1;
        }
    }
    //cout<<fixed<<setprecision(3)<<dist(l)<<endl;
    double ans = dist(l);
    printf("%.3f\n", ans);
    return 0;
}