#include <bits/stdc++.h>
using namespace std;

double p[20];
int n;
double l, r;
const double eps=1e-6;

double func(double x)
{
    double ret = 0.f;
    double _x=1.f;
    for(int i=n;i>=0;--i)
    {
        ret += _x*p[i];
        _x*=x;
    }
    return ret;
}

int main()
{
    cin>>n>>l>>r;
    for(int i=0;i<=n;++i)
    {
        cin>>p[i];
    }
    while(r-l>eps)
    {
        double mid1=l+(r-l)/3;
        double mid2 = l+(r-l)*2/3;
        double v1 = func(mid1);
        double v2 = func(mid2);
        
        if(v1<v2)
        {
            l=mid1;
        }
        else
        {
            r=mid2;
        }
        //cout<<l<<" "<<r<<endl;
    }
    cout<<l<<endl;
    return 0;
}