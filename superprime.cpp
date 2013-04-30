#include<stdio.h>
#include<algorithm>
using namespace std;
int v[100],w[100],N;
long long x;
int d[]={1,3,7,9};
 
int included(long long a,int b)
{
    int ok=0,la=0,lb=0,A[15],B[15];
    for(int i=1;i<=14;++i)
    {
        A[i]=0;
        B[i]=0;
    }
 
    while(a)
    {
        ++la;
        A[la]=a%10;
        a=a/10;
    }
 
    while(b)
    {
        ++lb;
        B[lb]=b%10;
        b=b/10;
    }
 
    sort(A+1,A+la+1);
    sort(B+1,B+lb+1);
 
    int k=1;
    for(int i=1;i<=la;++i)
    {
        if(A[i]==B[k])
            ++k;
    }
    if(k==lb+1)
        return 1;
    else
        return 0;
}
 
int prime(int x)
{
    if(x%2==0 && x!=2)
        return 1;
    if(x==2)
        return 0;
    for(int i=3;i*i<=x;++i)
        if(x%i==0)
            return 0;
    return 1;
 
}
 
int main()
{
    freopen("superp.in","r",stdin);
    freopen("superp.out","w",stdout);
    int first=1;
    int last=4;
    int k=4;
    v[1]=2;
    v[2]=3;
    v[3]=5;
    v[4]=7;
    w[1]=2;
    w[2]=3;
    w[3]=5;
    w[4]=7;
    int s=4;
    while(first<=last)
    {
        for(int i=0;i<=3;++i)
        {
            if(prime(v[first]*10+d[i])==1)
            {
                ++last;
                ++k;
                v[last]=v[first]*10+d[i];
                w[k]=v[last];
            }
        }
        ++first;
    }
    sort(w+1,w+k+1);
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
    {
        scanf("%lld",&x);
        for(int j=k;j>=1;--j)
        {
            if(included(x,w[j])==1)
            {
                printf("%d\n",w[j]);
                break;
            }
        }
 
    }
    return 0;
}
