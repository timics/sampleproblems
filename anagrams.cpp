#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int N,k,s=0,j,f[36030];
 
struct cuv
{
    char v[20];
}a[36030];
 
int comp(int x,int y)
{
    return (strcmp(a[x].v,a[y].v)>0);
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
    {
        scanf("%s",a[i].v);
        k=strlen(a[i].v);
        sort(a[i].v,a[i].v+k);
    }
    for(int i=1;i<=N;++i)
        f[i]=i;
    sort(f+1,f+N+1,comp);
    for(int i=2;i<=N;++i)
    {
        if(strcmp(a[f[i]].v,a[f[i-1]].v)==0)
        {
            ++s;
            j=1;
        }
        else
        {
            s=s+j;
            j=0;
        }
    }
    s=s+j;
    printf("%d",N-s);
    return 0;
}
