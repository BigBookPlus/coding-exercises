#include <bits/stdc++.h>
using namespace std;
int n,c;
int a[1000010];

bool check(int dis)
{
    int place=0;
    int cnt=1;
    for(int i=1;i<n;++i)
    {
        if(a[i]-a[place]>=dis)
        {
            ++cnt;
            place = i;
        }
    }
    if (cnt>=c) 
        return true;

    return false;
}
int main()
{
    cin>>n>>c;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a, a+n);

    int right = a[n-1]-a[0];
    int left = 0;
    int ans = 0;
    while(left<right)
    {
        int mid = left+(right-left)/2;
        if(check(mid))
        {
            ans = mid;
            left = mid+1;
        }
        else 
        {
            right = mid;
        }

    }
    cout<<ans<<endl;
    return 0;
}