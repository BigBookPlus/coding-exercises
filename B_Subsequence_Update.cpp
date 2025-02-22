#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, l, r;
        cin>>n>>l>>r;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }

        sort(a.begin(), a.begin()+r, std::greater<int>());
        sort(b.begin()+l-1, b.end());
        long long ans1 = 0;
        long long ans2 = 0;
        for (int i = l-1; i < r;++i)
        {
            ans1+=a[i];
            ans2+=b[i];
        }
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}