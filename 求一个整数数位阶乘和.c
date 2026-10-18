#include<stdio.h>
long long fac(int n)
{
    if(n==0||n==1)
        return 1;
    else  
    {
        int s=1;
        for(int i=2;i<=n;i++)
        {
            s*=i;
        }
        return s;
    }    
}
int main()
{
    int n;
    scanf("%d",&n);
    int a=0;
    long long s=0;
    while(n!=0)
    {
        a=n%10;
        n/=10;
        s+=fac(a);
    }
    printf("%lld",s);
    return 0;
}