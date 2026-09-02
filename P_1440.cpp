#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    deque<int> q;
    vector<int> a(n);

    for(int i=0;i<n;++i)
    {
        cin>>a[i];

        
        if(q.empty())
            cout<<"0"<<endl;
        else
        {
            //cout<<q.size()<<" ";
            cout<<a[q.front()]<<'\n';
        }
        while(!q.empty()&& i-q.front()>=m)
        {
            q.pop_front();
        }

        while(!q.empty()&&a[i]<=a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);


    }
    return 0;
}