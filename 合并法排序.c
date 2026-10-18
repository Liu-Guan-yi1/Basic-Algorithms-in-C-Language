#include <stdio.h>

int main() {
    int a[10], b[10], c[20];
    int i, ia, ib, ic;

    // 假设输入的a和b已经是排好序的，否则合并逻辑无效
    printf("Please input the first sorted array (10 nums):\n");
    for(i=0; i<10; i++) scanf("%d", &a[i]); // 修正：加下标

    printf("Please input the second sorted array (10 nums):\n");
    for(i=0; i<10; i++) scanf("%d", &b[i]); // 修正：加下标

    ia = 0; ib = 0; ic = 0;

    // 1. 双方都有元素时，比大小，小的放入c
    while(ia < 10 && ib < 10) {
        if(a[ia] < b[ib]) {
            c[ic] = a[ia];
            ia++;
        } else {
            c[ic] = b[ib];
            ib++;
        }
        ic++;
    }

    // 2. 如果a还有剩余，全部搬过去
    while(ia <= 9) {
        c[ic] = a[ia];
        ia++; ic++;
    }

    // 3. 如果b还有剩余，全部搬过去
    while(ib <= 9) {
        c[ic] = b[ib];
        ib++; ic++; // 修正：原图误写为 b++
    }

    printf("The merged array:\n");
    for(i=0; i<20; i++) {
        printf("%d ", c[i]); // 修正：加下标
    }
    
    return 0;
}
