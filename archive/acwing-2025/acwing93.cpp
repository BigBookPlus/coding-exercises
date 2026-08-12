#include <iostream>
#include <vector>
using namespace std;
void solve( int i, int n, int m, vector<int>& v)
{
    if (v.size()>m||v.size()+(n-i)<m)
        return;
    if (i==n && v.size()==m)
    {  
        bool f=false;
        for (int i=0;i<v.size();++i)
        {

                if (f==false)
                    cout<<v[i];
                else
                    cout<<' '<<v[i];
                f=true;
        }
        cout<<endl;
        return;
    }
    v.push_back(i+1);
    solve(i+1, n, m, v);

    v.pop_back();
    solve(i+1, n, m, v);

}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> v;
    solve(0, n, m, v);
    
    return 0;
}