#include<stdio.h>
int a[10100],b[10100],N;
 
void mul_a(int x)
{
    int carry=0;
    for(int i=1;i<=a[0];++i)
    {
        int y=a[i]*x+carry;
        a[i]=y%10;
        carry=y/10;
    }
    while(carry>0)
    {
        ++a[0];
        a[a[0]]=carry%10;
        carry=carry/10;
    }
}
 
void mul_b(int x)
{
    int carry=0;
    for(int i=1;i<=b[0];++i)
    {
        int y=b[i]*x+carry;
        b[i]=y%10;
        carry=y/10;
    }
    while(carry>0)
    {
        ++b[0];
        b[b[0]]=carry%10;
        carry=carry/10;
    }
}
 
void pow(int x)
{
    for(int i=1;i<=x;++i)
    {
        mul_a(x);
    }
}
 
void fact(int x)
{
    for(int i=1;i<=x;++i)
        mul_b(i);
}
 
void subtract()
{
    int carry=0;
    for(int i=1;i<=a[0];++i)
    {
        if(a[i]>=b[i]+carry)
        {
            a[i]=a[i]-b[i]-carry;
            carry=0;
        }
        else
        {
            a[i]=a[i]+10-carry-b[i];
            carry=1;
        }
    }
}
 
void show()
{
    for(int i=a[0];i>=1;--i)
        printf("%d",a[i]);
}
 
int main()
{
    scanf("%d",&N);
    a[0]=1;
    a[1]=1;
    b[0]=1;
    b[1]=1;
    pow(N);
    fact(N);
    subtract();
    show();
    return 0;
}
