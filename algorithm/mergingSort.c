//
// Created by MingR on 2021/4/1.
//
#include "base.c"

static void MSort (int [], int [], int ,int);
static void Merge (int [], int [], int , int, int);

/*
 * 归并排序 ★★★★★
 * 初始序列有n个记录，可以看成n个有序的子序列，每个子序列长度为1
 * 然后两两归并，得到n/2向上取整，重复操作直到得到长度为n的有序序列为止
 *
 * 采用分治法（Divide and Comquer）
 *
 * 时间复杂度：O(nlog2n)，空间复杂度：O(n+logn)
 * 使用的数据结构：倒置的完全二叉树
 */
static void MergeSort (SqList *L) {
    MSort(L->r, L->r, 1, L->length);
}

/*
 * 递归调用
 * 将SR[s..t]归并排序为TR1[s..t]
 * TR1<-SR
 */
static void MSort (int SR[], int TR1[], int s,int t) {
    int m;
    int TR2[MAXSIZE + 1];    // 中间数组，存放临时有序子序列
    if (s == t) {
        TR1[s] = SR[s];
    } else {
        m = (s + t) / 2;    // 将SR[s..t]平分为SR[s..m]和SR[m+1..t]
        MSort(SR, TR2, s, m);    // 递归将SR[s..m]归并为有序的TR2[s..m]
        MSort(SR, TR2, m + 1, t);    // 递归将SR[m+1..t]归并为有序TR2[m+1..t]
        Merge(TR2, TR1, s, m, t);    // 将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t]
    }
} // MSort end

/*
 * 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
 */
static void Merge (int SR[], int TR[], int i, int m, int n) {
    int j, k, l;

    // 将SR中记录从小到大归并入TR
    for (j = m + 1, k = i; i <= m && j <= n; k++) {
        if (SR[i] < SR[j]) {
            TR[k] = SR[i++];
        } else {
            TR[k] = SR[j++];
        }
    } // for end

    if (i <= m) {
        // 将剩余的SR[i..m]复制到TR
        for (l = 0; l <= m - i; l++) {
            TR[k + l] = SR[i + l];
        } // for end
    }

    if (j <= n) {
        // 将剩余的SR[j..n]复制到TR
        for (l = 0; l <= n - j; l++) {
            TR[k + l] = SR[j + l];
        } // for end
    }
} // Merge end

/**
 * 迭代调用
 * 对顺序表L做归并非递归排序
 */

static void merge_sort_test () {
    printf("merge_sort_test begin ...\n");
    SqList testData;
    gennerateRandData(&testData);
    printf("gennerateRandData after ...\n");
    printData(testData);
    MergeSort(&testData);
    printf("MergeSort after ...\n");
    printData(testData);

    printf("merge_sort_test end ...\n");
}