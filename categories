#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,k=1,ok,m=-1,nr=1,ma=1;
char a[20];
 
struct number
{
    int init;
    int ord;
}v[4050];
 
int comp(struct numar x, struct numar y)
{
    return x.ord<y.ord;
}
 
int main()
{
    scanf("%d",&n);
    int ind=n;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&v[i].init);
        int x=v[i].init;
        int y=0;
        while(x)
        {
            a[y]=x%10;
            x=x/10;
            ++y;
        }
        sort(a,a+y);
        for(int i=y-1;i>=0;--i)
            x=a[i]+10*x;
        v[i].ord=x;
 
    }
    sort(v+1,v+n+1,comp);
 
    for(int i=1;i<=n;++i)
    {
        if(v[i-1].ord==v[i].ord)
            ++m;
        if(v[i-1].ord!=v[i].ord)
        {
            if(i>1)
            {
                ok=1;
                ++k;
            }
            if(m==ma)
                ++nr;
            if(m>ma)
            {
                ind=i-1;
                ma=m;
                nr=1;
            }
            m=1;
        }
    }
    if(m>ma)
    {
        ma=m;
        nr=1;
    }
 
    if(ok==0)
    {
        printf("%d\n%d\n%d\n",1,n,1);
        for(int i=1;i<=n;++i)
            printf("%d ",v[i].init);
    }
 
    else
    {
        printf("%d\n%d\n%d\n",k,ma,nr);
        for(int i=ind;i>=ind-ma+1;--i)
            printf("%d ",v[i].init);
    }
    return 0;
}
