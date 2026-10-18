#include<stdio.h>


void init(int arr[], int *s) {
    int temp;
    int count=0;
    
    printf("请输入数字 (输入非数字字符结束):\n");
    
    //循环读取输入，直到输入失败（比如输入了字母）或达到数组上限
    while (scanf("%d", &temp) == 1 && count < 110)
    {
        arr[count] = temp;
        count++;
    }
    *s = count; 
    int ch;
    while((ch=getchar())!='\n' && ch!=EOF);
    //清空栈区的剩余字符，为main函数里的调用做准备
}

//交换两值，要用地址传参，否则无效
void swap(int* l,int* r)
{
    int tmp=*l;
    *l=*r;
    *r=tmp;
}

//取出中间值，作为基准值
int getmid(int num[],int left,int right)
{
    int mid=left+(right-left)/2;
    if(num[left]>num[right])
        swap(&num[left],&num[right]);
    if(num[left]>num[mid])
        swap(&num[left],&num[mid]);
    if(num[mid]>num[right])
        swap(&num[mid],&num[right]);
    //将元素地址传进去交换里面的值
    swap(&num[left],&num[mid]);
    return num[left];
}

void partition(int num[],int left,int right,int* lt,int* gt)
{
    int stand=num[left];
    int i=left+1;
    //快指针，向前检查，第一位是stand无需检查，从下一位开始
    *lt=left;
    *gt=right+1;
    //这两个都是慢指针，接受i检查的值
    while(i<*gt)//只要快指针还在大区后面，就向前检查
    {
        if(num[i]<stand)
        {
            (*lt)++;
            //小区间增大，准备容纳新值
            swap(&num[*lt],&num[i]);
            i++;//快指针继续检查下一个
        }
        else if(num[i]>stand)
        {
            (*gt)--;
            //大区间减小，要容纳新的值
            swap(&num[*gt],&num[i]);
            //此时i不能动，他要检查从大区那交换过来的值
        }
        else
        {
            i++;
            //此时，这个值和stand的值一样，留在原地就好，快指针继续向后走
        }
    }
    swap(&num[*lt],&num[left]);
    //将stand移到相同大小的区间里面
    //这里面所有的交换都不影响lt gt的值
}

void quickSort(int num[],int left,int right)
{
    if(left>=right)
        return;
    //先选出基准，再进行分区
    getmid(num,left,right);
    //先定义两个区的边界
    int lt,gt;
    //接受边界值，为之后的递归(排序小区和大区)做准备
    
    partition(num,left,right,&lt,&gt);
    //lt gt出了函数还要使用，自然用地址传参

    //递归处理两边小区的排序
    quickSort(num,left,lt-1);
    quickSort(num,gt,right);

}

int silding_window(int num[],int size,int target,int* bestL,int* bestR)
{
    //这里面,bestL和bestR是来接受符合的左右边界，他们不作为指针进行探测
    int windows_sum=0;
    int min_length=size+1;
    int left=0;
    int found=0;

    for(int i=0;i<size;i++)
    {
        windows_sum+=num[i];
        while(windows_sum>=target)
        {
            if(i-left+1<min_length)
            {
                min_length=i-left+1;//记录成绩
                *bestR=i;
                *bestL=left;
                found=1;//找到区间
            }
            windows_sum -= num[left];
            //删除一个数字
            left++;
        }
    }

    if(found)
    {
        return min_length;
    }
    return -1;
}

int main()
{
    int num[110];
    int size=0;
    init(num,&size);
    quickSort(num,0,size-1);
    //排序完毕,可以进行滑动区间查找

    printf("请输入你想要的目标值\n");
    int target;
    //输入目标值
    scanf("%d",&target);
    int bestleft=0;
    int bestright=bestleft;
    
    int minlen=silding_window(num,size,target,&bestleft,&bestright);
    //滑动区间查找完毕，left right是目标值的区间
    if(minlen != -1)
    {
        printf("最短区间\n");
        for(int i=bestleft;i<=bestright;i++)
        {
            printf("num[%d]=%d ",i,num[i]);
        }
        printf("\n最短长度是%d\n",minlen);
    }
    else
    {
        printf("抱歉，没有找到符合条件的最短数组\n");
    }
     
    return 0;
}