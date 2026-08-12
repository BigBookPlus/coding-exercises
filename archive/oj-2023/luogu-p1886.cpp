#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000010];
    int N, k;
    cin>>N>>k;
    deque<int> q;
    for(int i=0;i<N;++i)
    {
        cin>>a[i];
    }

    for (int i=0;i<N;++i)
    {
        if (!q.empty() && q.front()<=i-k) q.pop_front();
        while(!q.empty() && a[q.back()]>a[i])
            q.pop_back();
            
        q.push_back(i);
        if(i>=k-1)
        {    
            cout<<a[q.front()];
            if(i!=N-1)
                cout<<" ";
        }
    }
    cout<<endl;
    q.clear();
    for (int i=0;i<N;++i)
    {
        if (!q.empty() && q.front()<=i-k) q.pop_front();
        while(!q.empty() && a[q.back()]<a[i])
            q.pop_back();
            
        q.push_back(i);
        if(i>=k-1)
        {    
            cout<<a[q.front()];
            if(i!=N-1)
                cout<<" ";
        }
    }
    cout<<endl;
}