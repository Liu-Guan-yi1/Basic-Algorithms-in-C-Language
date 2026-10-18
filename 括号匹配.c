#include <stdio.h>

int main(void)
{
    char stack[10000];
    int top = 0;
    int ch;
    int valid = 1;//指示变量，判断什么时候退出

    while ((ch = getchar()) != '@' && ch != EOF)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            //检验是否到达到数组上限
            if (top == sizeof(stack))
            {
                valid = 0;
                break;
            }

            //没有到达就将字符存入数组
            stack[top] = ch;
          	top++;
            //为下一次扩容
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            //判断是不是第一个输入，如果第一次就输入右括号肯定就不匹配
            if (top == 0)
            {
                valid = 0;
                break;
            }
            //作括号判断完成后top++；所以最右边(栈顶)的左括号是top-1
            char left = stack[top - 1];

            //不匹配的条件
            if ((ch == ')' && left != '(') ||
                (ch == ']' && left != '[') ||
                (ch == '}' && left != '{'))
            {
                valid = 0;
                break;
            }
            //读到右括号时不需要将其存入数组，数组中只存入左括号

            top--;
            //如果匹配成功了，top后退一步，将最右边的左括号弹出(无效化)
        }
    }

    //指示变量valid为1，且栈顶为0，说明所有的括号都匹配成功
    if (valid && top == 0)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}