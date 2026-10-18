#include<stdio.h>

int judge(int n)
{
    if (n < 2)
        return 0;

    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
	int n;
  scanf("%d",&n);
  int flag=judge(n);
  if(flag==1)
  	printf("Y");
  if(flag==0)
  	printf("N");
	return 0;
}