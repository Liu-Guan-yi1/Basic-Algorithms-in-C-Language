#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int num[100][100];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &num[i][j]);
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            int appeared=0;
            int repeated=0;

            for(int x = 0;x <= i;x++)
            {
                for(int y = 0;y < n;y++)
                {
                    if(x==i&&y>=j)
                        break;
                        //检查之前的元素，一旦超出num[i][j]就停止循环
                    if(num[x][y]==num[i][j])
                        appeared=1;
                }
            }
            if(appeared)
                continue;
            //如果之前有一个一样的元素，这代表他已经被输出过了，直接跳过后面的输出代码

            for(int x = i;x < n;x++)
            {
                for(int y = 0;y < n;y++)
                {
                    if(x==i && y<=j)
                        continue;
                    if(num[x][y]==num[i][j])
                        repeated=1;
                }
            }
            if(repeated)
                printf("%d ",num[i][j]);
            //后面有一个一样的数，代表他是重复元素，
            //并且进入这个判断则代表他前面没有一样的数字，所以输出
        }
    }
    return 0;
}