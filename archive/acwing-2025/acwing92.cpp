#include <iostream>
#include <vector>
using namespace std;
void solve( int i, int n, vector<int>& v)
{
    if (i==n)
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
    solve(i+1, n, v);

    v.pop_back();
    solve(i+1, n, v);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    solve(0, n,  v);
    
    return 0;
}