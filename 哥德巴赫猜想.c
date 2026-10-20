#include <stdio.h>

/* 判断 n 是否为质数：是返回 1，否则返回 0 */
int is_prime(int n)
{
    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    /*
     * 只检查不超过 sqrt(n) 的奇数因子。
     * 用 i <= n / i 代替 i * i <= n，避免乘法溢出。
     */
    for (int i = 3; i <= n / i; i += 2) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

/* 找到一组质数之和，输出并返回 1；未找到则返回 0 */
int verify_goldbach(int n)
{
    for (int p = 2; p <= n / 2; p++) {
        int q = n - p;

        if (is_prime(p) && is_prime(q)) {
            printf("%d = %d + %d\n", n, p, q);
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    int limit;

    /* 限制范围，方便初学者运行和查看结果 */
    printf("请输入验证上限（4~100000）：");

    if (scanf("%d", &limit) != 1) {
        printf("输入错误：请输入整数。\n");
        return 1;
    }

    if (limit < 4 || limit > 100000) {
        printf("上限必须在 4~100000 之间。\n");
        return 1;
    }

    for (int n = 4; n <= limit; n += 2) {
        if (!verify_goldbach(n)) {
            printf("验证失败：未找到 %d 对应的两个质数。\n", n);
            return 1;
        }
    }

    printf("验证完成：4 到 %d 之间的所有偶数均满足猜想。\n",
           limit);

    return 0;
}
