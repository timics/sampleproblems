#include<stdio.h>
int x[10001],y[20001],a,b,N,s=0,ok;
 
inline void change(int i, int j)
{
    int in=x[i];
    x[i]=x[j];
    x[j]=in;
}
 
void solution()
{
    int c=a+1;
    int d=a+b+1;
    int e=1;
    for(int i=1;i<=a;++i)
    {
        int ok=0;
        if(x[i]==3)
        {
            for(int j=d;j<=N;++j)
                if(x[j]==1)
                {
                    ok=1;
                    y[e]=i;
                    y[e+1]=j;
                    e=e+2;
                    change(i,j);
                    d=1+j;
                    ++s;
                    break;
                }
            if(ok==0)
            {
                for(int j=c;j<=a+b;++j)
                    if(x[j]==1)
                    {
                        y[e]=i;
                        y[e+1]=j;
                        e=e+2;
                        change(i,j);
                        c=1+j;
                        ++s;
                        break;
                    }
            }
 
        }
        if(x[i]==2)
        {
            for(int j=c;j<=a+b;++j)
                if(x[j]==1)
                {
                    ok=1;
                    y[e]=i;
                    y[e+1]=j;
                    e=e+2;
                    change(i,j);
                    c=1+j;
                    ++s;
                    break;
                }
            if(ok==0)
            {
                for(int j=d;j<=N;++j)
                if(x[j]==1)
                {
                    y[e]=i;
                    y[e+1]=j;
                    e=e+2;
                    change(i,j);
                    d=1+j;
                    ++s;
                    break;
                }
            }
        }
    }
    int f=a+b+1;
    for(int i=a+1;i<=a+b;++i)
    {
        if(x[i]==3)
            for(int j=f;j<=N;++j)
                if(x[j]==2)
                {
                    y[e]=i;
                    y[e+1]=j;
                    e=e+2;
                    change(i,j);
                    f=1+j;
                    ++s;
                    break;
                }
    }
}
 
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&x[i]);
        if(x[i]==1) ++a;
        if(x[i]==2) ++b;
    }
    solution();
    printf("%d\n",s);
    for(int i=1;i<=s;++i)
        printf("%d %d\n",y[2*i-1],y[2*i]);
    for(int i=1;i<=N;++i)
        printf("%d ",x[i]);
    return 0;
}
