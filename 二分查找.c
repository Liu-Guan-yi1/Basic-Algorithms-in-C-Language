#include<stdio.h>

int find(int num[],int n,int target)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(num[mid]==target)
        {
            return mid;
        }
        if(num[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1;
}

int main()
{
    int num[10]={1,2,3,4,5,6,7,8,9,10};
    int target;
    scanf("%d",&target);
    int f=find(num,10,target);
    if(f==-1)
    {
        printf("没有找到\n");
    }
    else
    {
        printf("找到了,num[%d]=%d\n",f,num[f]);
    }
    return 0;
}