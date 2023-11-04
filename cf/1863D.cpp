#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
char d[250010];
char ans[250010];
int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n;++i)
        {
            scanf("%s", d + i*m);
        }
        bool failed = false;

        for (int i = 0; i < n;++i)
        {                
            int u_cntr = 0;

            for (int j = 0; j < m;++j)
            {
                if(*(d+i*m+j)=='U')
                {
                    if(u_cntr%2)
                    {
                        ans[i * m + j] = 'W';
                        ans[(i + 1) * m + j] = 'B';
                    }
                    else
                    {
                        ans[i * m + j] = 'B';
                        ans[(i + 1) * m + j] = 'W';
                    }
                    ++u_cntr;
                    //
                }
                else if(*(d+i*m+j)=='.')
                {
                    ans[i * m + j] = '.';
                }
            }
            if(u_cntr%2!=0)
            {
                failed = true;
                break;
            }
        }
        if (!failed)
        for (int j = 0; j < m;++j)
        {
            int l_cntr = 0;
            for (int i = 0; i < n;++i)
            {

                if(d[i*m+j]=='L')
                {
                    if(l_cntr%2)
                    {
                        ans[i * m + j] = 'W';
                        ans[i * m + j + 1] = 'B';
                    }
                    else
                    {
                        ans[i * m + j] = 'B';
                        ans[i * m + j + 1] = 'W';
                    }
                    ++l_cntr;
                }

            }           
            if(l_cntr%2!=0)
            {
                failed = true;
                break;
            }
        }

        if(failed)
            printf("-1\n");
        else
        {
            for (int i = 0; i < n;++i)
            {
                for (int j = 0; j < m;++j)
                {
                    printf("%c", ans[i * m + j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
