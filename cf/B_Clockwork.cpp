#include <iostream>
using namespace std;
int main()
{
    int n;
    std::cin >> n;
    while(n--)
    {
        int a;
        std::cin >> a;
        int i = 0;
        bool ans=true;
        bool flag = false;
        while(i< a)
        {
            int b;
            std::cin >> b;
            if(b<=i*2 || b<=(a-1-i)*2)
            {    
                if (flag==false)
                {   
                    ans=false;
                    flag = true;
                    cout<<"NO"<<endl;
                }

                //break;
            }
            i++;
        }
        if(ans && flag==false)
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}