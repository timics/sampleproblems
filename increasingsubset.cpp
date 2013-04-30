#include<stdio.h>
int a[100010],b[100010],s[100010],N,k=1;
int search(int x)
{
    int left=1;
    int right=k;
    int ret=1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(b[middle]>=x)
        {
            ret=middle;
            right=middle-1;
        }
        else
            left=middle+1;
    }
    return ret;
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;++i)
        scanf("%d",&a[i]);
    s[1]=1;
    b[1]=a[1];
    for(int i=2;i<=N;++i)
    {
        if(a[i]>b[k])
        {
            ++k;
            s[i]=k;
            b[k]=a[i];
        }
        else
        {
            int y=search(a[i]);
            s[i]=y;
            b[y]=a[i];
        }
    }
    printf("%d\n",k);
    int x=k;
    for(int i=N;i>=1;--i)
    {
        if(s[i]==k)
        {
            b[k]=a[i];
            --k;
        }
    }
    for(int i=1;i<=x;++i)
        printf("%d ",b[i]);
    return 0;
}
