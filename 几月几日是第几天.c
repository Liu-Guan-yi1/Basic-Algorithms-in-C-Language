#include <stdio.h>
#include <math.h>

int main()
{
    int day, month, year, sum, leap;

    printf("\n请输入年月日(如2020,1,1):\n");
    // 注意：scanf_s 是微软编译器特有的，如果是 GCC/Dev-C++ 请改为 scanf
    scanf_s("%d,%d,%d", &year, &month, &day);

    switch (month) /* 先计算某月以前月份的总天数 */
    {
        case 1: sum = 0; break;
        case 2: sum = 31; break;
        case 3: sum = 59; break;
        case 4: sum = 90; break;
        case 5: sum = 120; break;
        case 6: sum = 151; break;
        case 7: sum = 181; break;
        case 8: sum = 212; break;
        case 9: sum = 243; break;
        case 10: sum = 273; break;
        case 11: sum = 304; break;
        case 12: sum = 334; break;
        default:
            printf("\n数据错误.\n\n");
            break;
    }

    sum = sum + day; // 再加上某天的天数

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) /*判断是不是闰年*/
        leap = 1;
    else
        leap = 0;

    if (leap == 1 && month > 2) /*如果是闰年且月份大于2,总天数应该加一天*/
        sum++;

    printf("\n%d年%d月%d日是该年中的第%d天.\n\n", year, month, day, sum);

    return 0;
}
