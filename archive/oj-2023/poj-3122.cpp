#include <cstdio>
#include <cmath>
const double PI=acos(-1.0);
const double eps=1e-5;
double area[100010];
int m,n;
bool check(double a)
{
    int sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=(int)(area[i]/a);
    }
    if(sum>=m+1)
        return true;
    return false;
}

int main()
{
    int N;
    scanf("%d",&N);

    while(N--)
    {
        //cin>>n>>m;
        scanf("%d%d",&n,&m);
        double right = 0;
        double left =0;
        for(int i=0;i<n;++i)
        {
            int r;
            scanf("%d",&r);
            //cout<<i<<" "<<n;
            area[i]=PI*r*r;
            //cout<<area[i]<<endl;
            if(area[i]>right) right =area[i];

        }

        //while(right-left>eps)
        for(int i=0;i<100;++i)
        {
            double mid = left + (right-left)/2;
            if(check(mid)==true)
            {
                left = mid;
            }
            else
            {
                right = mid;
            } 
            //cout<<right-left<<endl;
        }
        printf("%.4lf\n",left);
       
    }
    return 0;
}