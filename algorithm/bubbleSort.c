//
// Created by MingR on 2021/4/1.
//

#include "base.c"

/*
 * 冒泡排序算法初级版，效率低，对顺序表做交换排序
 * 不符合两两比较相邻记录的冒泡排序思想，只是简单的交换排序
 */
static void BubbleSort0 (SqList *L) {
    int i, j;
    for (i = 1; i <= L->length; i++) {
        for (j = i + 1; j <= L->length; j++) {
            if (L->r[i] > L->r[j]) {
                swap(L, i, j);
            }
        }
    }
}

/*
 * 冒泡排序算法
 * 时间复杂度∑(i-1) = n(n-1)/2，D(n²)
 */
static void BubbleSort (SqList *L) {
    int i, j;
    for (i = 1; i <= L->length; i++) {
        for (j = L->length; j > i; j--) {
            if (L->r[j] < L->r[j - 1]) {
                swap(L, j - 1, j);
            }
        } // for end
    } // for end
}

/*
 * 冒泡排序算法，优化版本，避免有序情况再去冒泡循环
 */
static void BubbleSort2 (SqList *L) {
    int i, j;
    Status flag = TRUE;
    for (i = 1; i <= L->length && TRUE; i++) {
        flag = FALSE;
        for (j = L->length; j > i; j--) {
            if (L->r[j] < L->r[j - 1]) {
                swap(L, j - 1, j);
                flag = TRUE;
            }
        } // for end
    } // for end
}

static void bubble_sort_test () {
    printf("bubble_sort_test begin ...\n");
    SqList testData;
    gennerateRandData(&testData);
    printf("gennerateRandData after ...\n");
    printData(testData);
    BubbleSort2(&testData);
    printf("BubbleSort0 after ...\n");
    printData(testData);

    printf("bubble_sort_test end ...\n");
}


