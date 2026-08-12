#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    stack<pair<int,int>> a;
    int ans[10000+5]={0};
    for(int i=0;i<N;++i)
    {
        int v;
        cin>>v;

        if(a.empty() || a.top().second>=v)
        {
            a.push(make_pair(i,v));
        }
        else
        {
            while(!a.empty() && a.top().second<v)
            {
                ans[a.top().first]=i+1;
                a.pop();
            }
        }
    }

    for(int i=0;i<N;++i)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}