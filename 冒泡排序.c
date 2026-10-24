#include<stdio.h>

void swap(int* left, int* right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

void sort(int a[], int left, int right)
{
	for (int i = left;i < right - 1;i++)
		//决定循环趟数
	{
		int flag = 0;
		for (int j = 0;j < right - i - 1;j++)
			//决定每一次循环对比多少次，注意j<right-i-1 不是小于等于，防止越界
		{
			if (a[j] > a[j + 1])
				//对比相邻元素
			{
				swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
			//这里不要使用return;否则，当第一个值是最小值时，直接退出函数，无法对比交换后面值
		}
	}
}

int main()
{
	int a[9] = { 1,4,6,2,7,3,8,5,3 };
	int n = sizeof(a) / sizeof(a[0]);
	sort(a, 0, n);
	for (int i = 0;i < n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}