#include <stdio.h>
int n;
int order[20];
int flag[20];
void calc(int k)
{
    if(k==n+1)
    {
        for (int i = 1; i <= n;++i)
        {
            printf("%d ",order[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1;i<=n;++i)
    {
        if(flag[i]==1)
        {
            continue;
        }
        flag[i] = 1;
        order[k] = i;
        calc(k + 1);
        flag[i] = 0;
        order[k] = 0;
    }
}

int main()
{
    
    while(scanf("%d", &n)!=EOF)
    {
        calc(1);
    }
    return 0;
}