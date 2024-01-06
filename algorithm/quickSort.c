//
// Created by MingR on 2021/4/6.
//
#include "base.c"

static void QSort (SqList *, int, int);
static int Partition (SqList *, int, int);
static void QSort1 (SqList *, int, int);
static int Partition1 (SqList *, int, int);

/*
 * 快速排序算法 ★★★★★
 * 通过一趟排序将待排记录分割成独立的两部分，一部分记录比另一部分记录关键字小
 * 分别对两部分记录进行排序
 *
 * 平均时间复杂度：nlogn，最坏情况：n²，最好情况：nlogn
 *
 */
static void QuickSort (SqList *L) {
//    QSort(L, 1, L->length);

    QSort1(L, 1, L->length);
} // QuickSort end

/*
 * 对顺序表L的子序列L->r[low..high]做快速排序
 */
static void QSort(SqList *L, int low, int high) {
    int privot;

    if (low < high) {
        privot = Partition(L, low, high);    // 将L->r[low..high]一分为二，找出枢纽位置

        QSort(L, low, privot - 1);    // 对低子表递归排序
        QSort(L, privot + 1, high);    // 对高子表递归排序
    }
}

/*
 * 交换序列表中子表的记录，使枢轴记录到位，并返回其所在的位置
 * 此时在它之前的记录均不大于它
 */
static int Partition (SqList *L, int low, int high) {
    int privotkey;

    privotkey = L->r[low];    // 用子表的第一个记录作为枢轴记录

    // 从表的两端交替向中间扫描
    while (low < high) {
        // 找到比枢轴记录小的位置
        while (low < high && L->r[high] >= privotkey) {
            high--;
        }
        swap(L, low, high);    // 将比枢轴记录小的记录交换到低端

        // 找到比枢轴记录大的位置
        while (low < high && L->r[low] <= privotkey) {
            low++;
        }
        swap(L, low, high);     // 将比枢轴记录大的记录交换到高端
    } // while end

    return low;    // 此时low 应该等于high
}


/*
 * 尾递归
 */
static void QSort1 (SqList *L, int low, int high) {
    int privot;

    if (low < high) {
        privot = Partition1(L, low, high);    // 将L->r[low..high]一分为二，找出枢纽位置

        QSort1(L, low, privot - 1);    // 对低子表递归排序
        low = privot + 1;    // 尾递归
    }
}

/*
 * 交换序列表中子表的记录，使枢轴记录到位，并返回其所在的位置
 * 此时在它之前的记录均不大于它
 */
static int Partition2 (SqList *L, int low, int high) {
    int privotkey;

    privotkey = L->r[low];    // 用子表的第一个记录作为枢轴记录

    // 从表的两端交替向中间扫描
    while (low < high) {
        // 找到比枢轴记录小的位置
        while (low < high && L->r[high] >= privotkey) {
            high--;
        }
        swap(L, low, high);    // 将比枢轴记录小的记录交换到低端

        // 找到比枢轴记录大的位置
        while (low < high && L->r[low] <= privotkey) {
            low++;
        }
        swap(L, low, high);     // 将比枢轴记录大的记录交换到高端
    } // while end

    return low;    // 此时low 应该等于high
}

/*
 * 优化多次交换
 */
static int Partition1 (SqList *L, int low, int high) {
    int privotkey;

    privotkey = L->r[low];    // 用子表的第一个记录作为枢轴记录
    int temp = privotkey;    // 将枢轴关键字备份

    // 从表的两端交替向中间扫描
    while (low < high) {
        // 找到比枢轴记录小的位置
        while (low < high && L->r[high] >= privotkey) {
            high--;
        }
        L->r[low] = L->r[high];    // 采用替换而不是交换的方式进行操作
//        swap(L, low, high);    // 将比枢轴记录小的记录交换到低端

        // 找到比枢轴记录大的位置
        while (low < high && L->r[low] <= privotkey) {
            low++;
        }
        L->r[high] = L->r[low];    // 采用替换而不是交换的方式进行操作
//        swap(L, low, high);     // 将比枢轴记录大的记录交换到高端
    } // while end

    L->r[low] = temp;    // 将枢轴数值替换回来

    return low;    // 此时low 应该等于high
}

static void quick_sort_test () {
    printf("quick_sort_test begin ...\n");
    SqList testData;
    gennerateRandData(&testData);
    printf("gennerateRandData after ...\n");
    printData(testData);
    QuickSort(&testData);
    printf("QuickSort after ...\n");
    printData(testData);

    printf("quick_sort_test end ...\n");
}
