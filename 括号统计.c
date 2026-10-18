#include<stdio.h>
int main(){
int ch;
int round=0;
int square=0;
int brace=0;
while((ch=getchar())!='@'&&ch!=EOF)
{
    if(ch=='{')
    brace++;
    if(ch=='}')
    brace--;
    if(ch==']')
    square++;
    if(ch=='[')
    square--;
    if(ch=='(')
    round++;
    if(ch==')')
    round--;
}
    if(brace!=0)
    printf("{}");
    if(square!=0)
    printf("[]");
    if(round!=0)
    printf("()");
    if(brace==0&&square==0&&round==0)
    printf("NULL");
return 0;
}