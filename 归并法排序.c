#include <stdio.h>
/*
归并排序的本质其实是将一个数组的下标通过递归分解为只有一个元素的小区间，
再通过读写指针和一个临时数组进行排序，
最后将每次合并后产生的临时数组覆盖回原数组的那两个小区间
*/

static void merge(int a[], int temp[],
    int left, int mid, int right)
    //默认是[left,right)
    //合并函数不要求左右两区间大小相等，只要求有序即可
{
    //读写指针
    int i = left;  // 左半部分：[left, mid)
    int j = mid;   // 右半部分：[mid, right)
    int k = left;  // 临时数组的写入位置

    while (i < mid && j < right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
            /*
            等价于
            temp[k]=a[i];
            k++;
            i++;
            */
        }
        else {
            temp[k++] = a[j++];
        }
        //不要用两个if判断
    }

    // 复制左半部分剩余的元素
    while (i < mid) {
        temp[k++] = a[i++];
    }

    // 复制右半部分剩余的元素
    while (j < right) {
        temp[k++] = a[j++];
    }

    // 将合并结果复制回原数组
    for (int p = left; p < right; p++) {
        a[p] = temp[p];
    }
}

static void merge_sort_recursive(int a[], int temp[],
    int left, int right)//拆分数组
    //归并排序并不是真正的拆分数组，而是把数组的下标拆分成不同的区间，这是为什么在拆分函数里见不到拆分出来的数组
{
    // 0 个或 1 个元素，不需要排序
    if (right - left <= 1)//这个是递归的终止条件，当数组拆分到只剩下一个元素时，停止，不能改
    {
        return;
    }

    int mid = left + (right - left) / 2;

    //递归调用，要把左右两边都拆分好后才能进入后续的合并
    merge_sort_recursive(a, temp, left, mid);
    //先把左边彻底拆分完，合并排序好才能进入下一行代码
    merge_sort_recursive(a, temp, mid, right);
    //此时左边已经排序好了，开始拆分排序右边，也是排序完全后进入下一行代码

    //当数组被拆分为一个元素的小方块时，就会进入下面这个合并，先合并一个元素的，在合并更多元素的
    merge(a, temp, left, mid, right);
}

int main(void)
{
    int a[] = { 5, 3, 8, 1, 2 };
    int n = (int)(sizeof(a) / sizeof(a[0]));

    int temp[n];

    merge_sort_recursive(a, temp, 0, n);
    //这里的区间默认为左闭右开，所以这里直接写n，不会导致访问到数组外面

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}