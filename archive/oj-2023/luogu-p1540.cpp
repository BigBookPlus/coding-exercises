#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    queue<int> a;
    int hash[1001] = {0};
    printf("%d\n", sizeof(hash));
    scanf("%d%d", &m, &n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int v;
        scanf("%d", &v);

        if (!hash[v])
        {
            ++ans;
            hash[v] = 1;
            a.push(v);
            while (a.size() > m)
            {
                hash[a.front()] = 0;
                a.pop();
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}