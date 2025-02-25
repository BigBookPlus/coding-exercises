#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print(vector<vector<int>> v)
{
    for(int i=0;i<v.size();++i)
    {
       for(int j=0;j<v[i].size();++j)
       {
           cout<<v[i][j]<< " " ;
       }
       cout<<endl;
    }
}
bool op(vector<vector<int>> &v, int i, int j)
{
    if (i>=0&&i<5&&j>=0&&j<5)
    {
        v[i][j]=(v[i][j]+1)%2;
        if (i-1>=0)
            v[i-1][j]=(v[i-1][j]+1)%2;
        if (j-1>=0)
            v[i][j-1]=(v[i][j-1]+1)%2;
        if (i+1<5)
            v[i+1][j]=(v[i+1][j]+1)%2;
        if (j+1<5)
            v[i][j+1]=(v[i][j+1]+1)%2;
        return true;
    }
    return false;
}

bool check(vector<vector<int>> v)
{
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
        {
            if(v[i][j]!=1)
                return false;
        }
    }
    return true;
}

void solve(vector<vector<int>> v)
{
    int ans=7;
    for(int i=0;i<1<<5;++i)
    {
        vector<vector<int>> v1=v;
        int cnt=0;
        if(!check(v1))
        {
            for (int j=0;j<5;++j)
            {
                if ((i&(1<<j))!=0)
                {
                    if(op(v1, 0, j))
                        ++cnt;
                    if(check(v1))
                        break;
                }
            }
        }
        if(!check(v1))
        {
            for(int i=0;i<4;++i)
            {
                for(int j=0;j<5;++j)
                {
                    if (v1[i][j]==0)
                    {
                        if(op(v1, i+1, j))
                            ++cnt;
                        if(check(v1))
                            break;
                    }
                }
            }
        }

        //print(v1);
        
        
        ans = min(ans, cnt);
    }
    
    if (ans >= 7)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
}



int main()
{
    int n;
    cin>>n;
    while(n--)
    {
       string line;
       vector<string> v;
       for(int i=0;i<5;++i) {
           cin>>line;
           v.push_back(line);
       }
       vector<vector<int>> v1(5);
       for(int i=0;i<v.size();++i)
       {
            for(int j=0;j<v[i].size();++j)
            {
                v1[i].push_back(v[i][j]-'0');
            }
       }

       solve(v1);
    }
}