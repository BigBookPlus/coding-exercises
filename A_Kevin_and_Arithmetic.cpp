#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    std::cin >> n; 
    while(n--)
    {
        int m,a;
        int s = 0;
        int ans = 0;
        cin>>m;
        int i = 0;
        int j=0;
        int _m = m;
        while(_m--)
        {
            cin >> a;
            if(a%2==0)
            {
                i++;
            }
            else
            {
                j++;
            }

        }

        if(i>0)
            ans = j + 1;
        else
            ans = j - 1;
        cout << ans << endl;
    }
    return 0;
}