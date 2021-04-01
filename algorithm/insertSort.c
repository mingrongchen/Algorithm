//
// Created by MingR on 2021/4/1.
//
#include "base.c"

/*
 * 直接插入排序：基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的有序表
 * 时间复杂度为O(n²)，性能比冒泡和简单选择排序性能好一些
 */
static void InsertSort (SqList *L) {
    int i, j;

    for (i = 2; i <= L->length; i++) {
        if (L->r[i] < L->r[i - 1]) {
            L->r[0] = L->r[i];    // 设置哨兵，临时变量
            // 记录后移并插入
            for (j = i -1; L->r[j] > L->r[0] && j > 0; j--) {
                L->r[j + 1] = L->r[j];    // 记录后移
            } // for end

            // 插入到正确的位置
            L->r[j + 1] = L->r[0];
        }
    } // for end
} // InsertSort end

static void insert_sort_test () {
    printf("insert_sort_test begin ...\n");
    SqList testData;
    gennerateRandData(&testData);
    printf("gennerateRandData after ...\n");
    printData(testData);
    InsertSort(&testData);
    printf("InsertSort after ...\n");
    printData(testData);

    printf("insert_sort_test end ...\n");
}