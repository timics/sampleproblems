#include<stdio.h>
#include<algorithm>
using namespace std;
int v[101],N,s,t;
struct sum
{
    int x;
    int y;
    int z;
} a[1000001];
 
int comp(sum a, sum b)
{
    return a.x+a.y+a.z<b.x+b.y+b.z;
}
 
inline int caut(int d)
{
    int st=1;
    int dr=t;
    while(st<=dr)
    {
        int mij=(st+dr)/2;
        if(a[mij].x+a[mij].y+a[mij].z>d)
            dr=mij-1;
        else if(a[mij].x+a[mij].y+a[mij].z<d)
            st=mij+1;
        else
            return mij;
    }
    return 0;
}
int main()
{
    scanf("%d%d",&N,&s);
    for(int i=1;i<=N;++i)
        scanf("%d",&v[i]);
    for(int i=1;i<=N;++i)
        for(int j=i;j<=N;++j)
            for(int k=j;k<=N;++k)
            {
 
                a[++t].x=v[i];
                a[t].y=v[j];
                a[t].z=v[k];
            }
    sort(a+1,a+t+1,comp);
    for(int i=1;i<=t;++i)
    {
        int ret=caut(s-a[i].x-a[i].y-a[i].z);
        if(ret!=0)
        {
            printf("%d %d %d %d %d %d",a[i].x,a[i].y,a[i].z,a[ret].x,a[ret].y,a[ret].z);
            return 0;
        }
    }
    printf("%d",-1);
    return 0;
}
