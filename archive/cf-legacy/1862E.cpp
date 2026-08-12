#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int a[200010];
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m, d;
        scanf("%lld%lld%lld", &n, &m, &d);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        set<pair<ll,ll>> s;
        ll ans = 0;
        ll sum = 0;
        for (int i = 0; i < n;++i)
        {
            ll cur = a[i] - (i + 1) * d;
            ans = max(sum + cur, ans);
            if(a[i]>0)
            {   
                s.insert(make_pair(a[i],i));
                sum += a[i];
                if(s.size()>=m)
                {
                    sum -= (s.begin()->first);
                    s.erase(s.begin());
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}