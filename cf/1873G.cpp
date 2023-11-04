#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
char str[200010];
int main(){
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int ans = 0;
        scanf("%s", str);
        int len = strlen(str);
        /*for (int i = 0; i < len-1;++i)
        {
            if(str[i]=='A'&&str[i+1]=='B')
            {
                ans1++;
                str[i] = 'B';
                str[i + 1] = 'C';
                ++i;
            }
            else if(str[i]=='B'&&str[i+1]=='A')
            {
                ans1++;
                str[i] = 'C';
                str[i + 1] = 'B';
            }
        }

        for (int i = len-1; i >0;--i)
        {
            if(str[i-1]=='A'&&str[i]=='B')
            {
                ans1++;
                str[i-1] = 'B';
                str[i] = 'C';
                
            }
            else if(str[i-1]=='B'&&str[i]=='A')
            {
                ans1++;
                str[i-1] = 'C';
                str[i] = 'B';
                --i;
            }
        }*/
        bool all = (str[0] == 'B' || str[len - 1] == 'B');

        for (int i = 0; i < len-1;++i)
        {
            if (str[i]=='B'&& str[i+1] == 'B')
                all = true;
        }

        std::vector<int> lens;
        int cur = 0;
        for (int i = 0; i < len;++i)
        {
            if(str[i]=='A')
            {
                cur++;
            }
            else
            {
                if(cur>0)
                    lens.push_back(cur);
                cur = 0;
            }
        }
        if(cur>0)
            lens.push_back(cur);        

        sort(lens.begin(), lens.end());
        
        if(all&&lens.size()>0)
        {
            ans += lens[0];
        }

        for (int i = 1;i<lens.size();++i)
        {
            ans+=lens[i];
        }

        printf("%d\n", ans);
    }
    return 0;
} 