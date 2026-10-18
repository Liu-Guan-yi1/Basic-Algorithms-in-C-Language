#include <stdio.h>


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

int main() {
    int num[110];
    int size = 0; 
    
    // size出了函数还要使用，传递 size 的地址 (&size)
    init(num, &size); 
    //经过函数调用后，size表示数组元素个数
    
    printf("交换前 (共 %d 个数字):\n", size);
    
    // 循环打印，注意是 i < size，不是 i <= size
    for (int i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    
    quickSort(num,0,size-1);

    printf("交换后的顺序如下（从左至右依次增大）\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }

    return 0;
}
    