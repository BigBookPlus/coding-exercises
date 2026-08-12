#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll A, B, C;
int n,m;
ll t[100010], b[100010];

ll calc1(int p)
{
    ll x=0,y=0;
    for(int i=0;i<m;++i)
    {
        if(p>b[i]) x+=p-b[i];
        else y+=b[i]-p;
    }
    if (A<B)  return min(x,y)*A+(y-min(x,y))*B;
    else return y*B;
}

ll calc2(int p)
{
    ll sum=0;
    for(int i=0;i<n;++i)
    {
        if(p>t[i]) sum+=(p-t[i])*C;
    }
    return sum;
}

int main()
{
    cin>>A>>B>>C;
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>t[i];
    for(int i=0;i<m;++i) cin>>b[i];
    sort(t, t+n);
    sort(b, b+m);
    int left =1, right = 100010;
    ll ans = 1e16;
    if(C>=1e16)
    {
        cout<<calc1(t[0])<<endl;
        return 0;
    }
    while(right-left>2)
    {
        int mid1 = left+(right-left)/3;
        int mid2 = right-(right-left)/3;
        ll v1 = calc1(mid1)+calc2(mid1);
        ll v2 = calc1(mid2)+calc2(mid2);
        if (v1<v2) right = mid2;
        else left =mid1;
    }

    for(int i=left;i<=right;++i)
    {
        ll v = calc1(i)+calc2(i);
        ans = min(ans, v);
    }

    cout<<ans<<endl;
    
    return 0;
}