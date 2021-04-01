//
// Created by MingR on 2021/4/1.
//
#include "base.c"

/*
 * 希尔排序
 * 有跨度的插入排序
 * 时间复杂度为O(nlog2n)
 */
static void ShellSort (SqList *L) {
    int i, j;
    int increment = L->length;

    do{
        increment = increment / 3 + 1;    // 增量序列

        for (i = increment + 1; i <= L->length; i++) {
            if (L->r[i] < L->r[i - increment]) {
                // 需将L->r[i]插入有序增量子表中
                L->r[0] = L->r[i];    // 暂存在L->r[0]，临时变量

                for (j = i - increment; L->r[j] > L->r[0] && j > 0; j -= increment) {
                    L->r[j + increment] = L->r[j];    // 记录后移，直接插入位置

                } // for end

                // 找到对应位置并且插入
                L->r[j + increment] = L->r[0];
            }


        }
    } while (increment > 1);
}

static void ShellSort2 (SqList *L) {
    int i, j;
    int increment;

    for (increment =  L->length / 3; increment > 0; increment /= 3) {
        for (i = increment + 1; i <= L->length; i++) {
            if (L->r[i] < L->r[i - increment]) {
                // 需将L->r[i]插入有序增量子表中
                L->r[0] = L->r[i];    // 暂存在L->r[0]，临时变量

                for (j = i - increment; L->r[j] > L->r[0] && j > 0; j -= increment) {
                    L->r[j + increment] = L->r[j];    // 记录后移，直接插入位置

                } // for end
                // 找到对应位置并且插入
                L->r[j + increment] = L->r[0];
            }
        } // for end
    } // for end
}

static void shell_sort_test () {
    printf("shell_sort_test begin ...\n");
    SqList testData;
    gennerateRandData(&testData);
    printf("gennerateRandData after ...\n");
    printData(testData);
//    ShellSort(&testData);
    ShellSort2(&testData);
    printf("ShellSort after ...\n");
    printData(testData);

    printf("shell_sort_test end ...\n");
}