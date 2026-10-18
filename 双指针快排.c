#include <stdio.h>

/* 模块一：交换两个整数 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* 模块二：初始化数组，读取输入 */
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

/* 模块三：取中间值作为基准 */
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

/* 模块四：完成一轮分区，返回基准的最终下标 */
int partition(int a[], int left, int right)
{
    getmid(a, left, right);
    int pivot = a[left];
    int i = left;
    int j = right;

    while (i < j)
    {
        /* 从右边找小于基准的数 */
        while (i < j && a[j] >= pivot)
        {
            j--;
        }

        /* 从左边找大于基准的数 */
        while (i < j && a[i] <= pivot)
        {
            i++;
        }

        /* 尚未相遇，交换两个位置不合适的数 */
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }

    /* 相遇后，让基准归位 */
    swap(&a[left], &a[i]);

    return i;
}

/* 模块五：递归排序 */
void quickSort(int a[], int left, int right)
{
    /* 没有元素或者只有一个元素，无需排序 */
    if (left >= right)
    {
        return;
    }

    int pos = partition(a, left, right);

    quickSort(a, left, pos - 1);
    quickSort(a, pos + 1, right);
}

/* 模块六：准备数据、调用排序、打印结果 */
int main(void)
{
    int a[110];
    int n;
    init(a, &n);

    printf("交换前 (共 %d 个数字):\n", n); 

    // 循环打印，注意是 i < size，不是 i <= size
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    quickSort(a, 0, n - 1);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}