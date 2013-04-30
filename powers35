#include<stdio.h>
int N;
inline long long bi3(int b)
{
    long long y=0;
    int z=b;
    int t;
    long long a=1;
    while(z>0)
    {
        t=z&1;
        y+=t*a;
        a=a*3;
        z>>=1;
    }
    return y;
}
 
inline long long bi5(int b)
{
    long long y=0;
    int z=b;
    int t;
    long long a=1;
    while(z>0)
    {
        t=z&1;
        y+=t*a;
        a=a*5;
        z>>=1;
    }
    return y;
}
int main()
{
    scanf("%d",&N);
    int a3=1;
    int a5=1;
    while(a5<=N)
    {
        long long x5=bi5(a5);
        if(a3<=N)
        {
            long long x3=bi3(a3);
            if(x3<=x5)
            {
                printf("%lld\n",x3);
                ++a3;
            }
            else
            {
                printf("%lld\n",x5);
                ++a5;
            }
        }
        else
        {
            printf("%lld\n",x5);
            ++a5;
        }
    }
    return 0;
}
