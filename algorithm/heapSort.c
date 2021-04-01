//
// Created by MingR on 2021/4/1.
//
#include "base.c"

static void HeapAdjust(SqList *, int, int);
/*
 * 构造一个大顶堆，其中堆顶就是最大元素，将它移出
 * 将剩余n-1个序列重新构造一个堆，然后反复执行
 *
 * 解决两个问题
 * 1、如何将一个无序序列构造成一个堆
 * 2、输出堆顶元素后，调整剩余元素成为一个新的堆
 *
 * 时间复杂度：O(nlog2n)，最好、最坏、平均时间复杂度一样
 *
 * 使用的数据结构：完全二叉树
 */
static void HeapSort(SqList *L) {
    int i;

    /*
     * 把L中的r构造成一个大顶堆
     * 为什么从4到1，而不是1到9或者9到1，
     * 可以理解处理根节点，他们都是有孩子的节点
     */
    for (i = L->length / 2; i > 0; i--) {
        HeapAdjust(L, i, L->length);
    }

    for (i = L->length; i > 1; i--) {
        /*
         * 位置1为大顶堆的根节点
         * 将堆顶记录和当前未经排序子序列的最后一个位置进行交换
         */
        swap(L, 1, i);
        HeapAdjust(L, 1, i - 1);    // 将L->r[1..i-1]重新调整为大顶堆
    }

}

/*
 * 已知L->r[s..m]中记录的关键字除了L->r[s]之外均满足堆的定义
 * 调整L->r[s]的关键字，使L->r[s..m]成为一个大顶堆
 */
static void HeapAdjust(SqList *L, int s, int m) {
    int temp, j;
    temp = L->r[s];

    /*
     * 沿关键字较大的孩子节点向下筛选
     * 沿左孩子
     */
    for (j = 2 * s; j <= m; j *= 2) {
        // 找到最大孩子的位置
        if (j < m && L->r[j] < L->r[j + 1]) {
            ++j;    // j为关键字中较大的记录的下标
        }

        // rc应该插入在位置s上，根节点上，结束循环
        if (temp >= L->r[j]) {
            break;
        }

        L->r[s] = L->r[j];
        s = j;
    } // for end

    L->r[s] = temp;    // 插入
}

static void heap_sort_test () {
    printf("heap_sort_test begin ...\n");
    SqList testData;
    gennerateRandData(&testData);
    printf("gennerateRandData after ...\n");
    printData(testData);
    HeapSort(&testData);
    printf("ShellSort after ...\n");
    printData(testData);

    printf("heap_sort_test end ...\n");
}