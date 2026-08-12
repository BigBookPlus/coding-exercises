#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int ans = 0;
        vector<int> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int l=0, r=n-1;
        while(l<r)
        {
            if(a[l]+a[r]==k)
            {
                ans++;
                l++;
                r--;
            }
            else if(a[l]+a[r]<k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }   
        cout<<ans<<endl;
    }
    return 0;
}