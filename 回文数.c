#include<stdio.h>
int jud(int a)
{
    int c=0;
    while(a>c)
    {
        c=c*10+a%10;
        a/=10;
    }
    if(c==a||c/10==a)
        return 1;
    else
        return 0;
}

int main()
{
    int n=0;
    scanf("%d",&n);
    int flag=jud(n);
    if(flag==1)
        printf("%d是回文数",n);
    if(flag==0) 
        printf("%d不是回文数",n);
    return 0;
}