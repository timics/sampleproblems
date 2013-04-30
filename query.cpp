#include<stdio.h>
int a[100010],y[200010],x,z,N,M,indf1=1,ind1=1,b1=1,indf2=1,ind2=1,b2=1;
int main()
{
    scanf("%d %d",&N,&M);
 
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)
            a[i]=-1;
        a[i]=a[i-1]+a[i];
        if((i>2)&&(a[i]==a[i-2]))
           x=i;
    }
    int mi1=0;
    int ma1=a[1];
    int ma2=0;
    int mi2=a[1];
 
    for(int i=1;i<=N;++i)
    {
        if(a[i-1]<mi1)
        {
            mi1=a[i-1];
            ind1=i;
        }
        if(a[i]-mi1>ma1)
        {
            ma1=a[i]-mi1;
            b1=i;
            indf1=ind1;
        }
 
        if(a[i-1]>ma2)
        {
            ma2=a[i-1];
            ind2=i;
        }
        if(a[i]-ma2<mi2)
        {
            mi2=a[i]-ma2;
            b2=i;
            indf2=ind2;
        }
    }
 
    for(int i=indf1-1;i<b1;++i)
        y[a[b1]-a[i]+N]=i+1;
 
    for(int i=indf2-1;i<b2;++i)
        y[a[b2]-a[i]+N]=i+1;
 
    for(int i=1;i<=M;++i)
    {
        scanf("%d",&z);
        if(z==0)
        {
            if(x==0)
                printf("%d\n",-1);
            else
                printf("%d %d\n",x-1,x);
        }
        if(z<0)
        {
            if(y[z+N]==0)
                printf("%d\n",-1);
            else
                printf("%d %d\n",y[z+N],b2);
        }
        if(z>0)
        {
            if(y[z+N]==0)
                printf("%d\n",-1);
            else
                printf("%d %d\n",y[z+N],b1);
        }
    }
    return 0;
}
