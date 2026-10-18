#include<stdio.h>

int remove(int num[],int n)
{
  int new_len=0;
  for(int i=0;i<n;i++)
  {
    int is_dup=0;
    for(int j=0;j<new_len;j++)
    {
      if(num[i]==num[j])
      {
        is_dup=1;
        break;
      }
    }
    if(is_dup==0)
    {
      num[new_len]=num[i];
      new_len++;
    }
  }
  return new_len;
}

int main()
{
  int n;
  scanf("%d",&n);
  int num[100];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&num[i]);
  }
  int new_len=remove(num,n);
  for(int i=0;i<new_len;i++)
  {
    printf("%d",num[i]);
    if(i<new_len-1)
    {
      printf(" ");
    }
  }
  printf("\n");
    
  return 0;
}