#include<stdio.h>
int main()
{
    for(int i=1;i<=9;i++)
    {
        printf("%d ",i);
        for(int j=1;j<=i;j++)
        {
            printf("%3d",i*j);
        }
        printf("\n");
    }
    printf("* ");
    for(int i=1;i<=9;i++)
    {
        printf("%3d",i);
    }
    return 0;
}