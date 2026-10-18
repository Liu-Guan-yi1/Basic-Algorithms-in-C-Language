#include <stdio.h>

int main() {
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    int left=n,count=0,pos=k;//left记录剩余人数，count是当前报数，pos记录当前位置
    int man[n];
    for(int i=0;i<n;i++)
        man[i]=1; //给人赋予指示变量，1代表还在，0表示不在
    while(left>1)
    {
        if(man[pos]==1)
        {
            count++;//用count++来表示报数
            if(count==m)
            {
                man[pos]=0;//标记此人退出游戏
                left--;
                count=0;
            }
        }
        pos=(pos+1)%n;//无论那个人在不在圈里都要跳到下一个人，所以此处不用else
    }
    //让人出列的部分结束，接下来是找人
    for(int i=0;i<n;i++)
    {
        if(man[i]==1)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}