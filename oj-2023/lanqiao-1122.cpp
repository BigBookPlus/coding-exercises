#include <bits/stdc++.h>
#define INF  0x6fffffff
using namespace std;
typedef pair<int,int> iPair;
int n, m, b;
vector<vector<iPair>> e;
vector<int> pv;

void dijstra()
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> q;
    vector<int> dist(n+1, INF);
    vector<bool> visited(n+1, false);
    int src=1;
    q.push(make_pair(0, src));
    dist[src]=0;
    while(!q.empty())
    {
        int pt = q.top().second;
        int pw = q.top().first;
        q.pop();
        if(visited[pt]==true)
            continue;

        visited[pt]=true;

        for(int i=0;i<e[pt].size();++i)
        {
            int t = e[pt][i].first;
            int w = e[pt][i].second;
            if(dist[t]>dist[pt]+w)
            {
                dist[t] = dist[pt]+w;
                q.push(make_pair(dist[t], t));
            }
        }
    }
    for(int i=1;i<=n;++i)
        cout<<dist[i]<<" ";
    cout<<endl;
}


int main()
{
    cin>>n>>m;
    e.resize(n+1);
    for(int i=0;i<m;++i)
    {
        int a,b,w;
        cin>>a>>b>>w;
        //e[a].push_back(make_pair(b,w));
        //e[b].push_back(make_pair(a,w));
    }
    dijstra();
    return 0;
}