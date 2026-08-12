#include <bits/stdc++.h>
using namespace std;

int  a[1000010]; 

int main()
{
    int N;
    cin>>N;
    int len=0;
    for(int i=0;i<N;++i)
    {
        int op, v;
        cin>>op;
        if(op==1)
        {
            cin>>v;
            len++;
            int idx=len;
            a[len]=v;
            while(idx>1 && a[idx]<a[idx/2])
            {
                swap(a[idx], a[idx/2]);
                idx=idx/2;
            }

        }
        else if(op==2)
        {
            cout<<a[1]<<endl;
        }
        else if(op==3)
        {
            a[1]=a[len];
            len--;
            int idx =1;
            while(idx*2<=len)
            {
                int son = idx*2;
                if(son+1<=len && a[son+1]<a[son])
                {
                    son=son+1;
                }
                if(a[son]<a[idx])
                {
                    swap(a[son], a[idx]);
                    idx=son;
                }
                else
                {
                    break;
                }
            }
        }

    }
    return 0;
}