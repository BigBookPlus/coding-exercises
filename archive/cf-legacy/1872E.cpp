#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int a[100010];
int a_buf[100010];
char s[100010];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n;++i)
        {
            scanf("%d", &a[i]);
        }
        scanf("%s", s);
        int s_len = strlen(s);

        int buf = a[0];
        a_buf[0] = 0;
        for (int i = 1; i <= n;++i)
        {
            a_buf[i] = a_buf[i-1] ^ a[i];
        }
        int ans0=0, ans1=0;

        for (int i = 0; i < s_len;++i)
        {
            if(s[i]-'0'==0)
            {
                ans0 ^= a[i+1];
            }
            else if (s[i]-'1'==0)
            {
                ans1 ^= a[i+1];                    
            }
        }
        int q;
        scanf("%d", &q);
        while(q--)
        {
            int op;
            int l, r;
            int v;
            scanf("%d", &op);


            if(op==1)
            {
                scanf("%d %d", &l, &r);

                int _buf = a_buf[l - 1] ^ a_buf[r];

                ans1 ^= _buf;
                ans0 ^= _buf;
            
            }
            else if(op==2)
            {
                scanf("%d", &v);
                int ans = 0;
                bool find = false;
                if(v==0)
                    ans = ans0;
                if(v==1)
                    ans = ans1;
                printf("%d ", ans);
            }
        }
    }
    return 0;
}