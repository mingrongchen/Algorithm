//
// Created by MingR on 2021/4/1.
//
#include "base.c"

/*
 * 简单选择排序算法
 * 通过n-i次关键字间的比较，从n-i+1个记录中选出关键字最小的记录，并和第i个记录交换
 * 比较多次，交换一次
 * 时间复杂度∑(i-1) = n(n-1)/2，D(n²)
 */
static void SelectSort (SqList *L) {
    int i, j, minIndex;

    for (i = 1; i <= L->length; i++) {
        minIndex = i;
        for (j = i + 1; j <= L->length; j++) {
            if (L->r[j] < L->r[minIndex]) {
                minIndex = j;
            }
        } // for end

        // 从n-i+1个记录中找到关键字最小的位置，并交换
        if (minIndex != i) {
            swap(L, i , minIndex);
        }
    } // for end
}


static void select_sort_test () {
    printf("select_sort_test begin ...\n");
    SqList testData;
    gennerateRandData(&testData);
    printf("gennerateRandData after ...\n");
    printData(testData);
    SelectSort(&testData);
    printf("SelectSort after ...\n");
    printData(testData);

    printf("select_sort_test end ...\n");
}