//
// Created by MingR on 2021/3/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAXSIZE 10

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct {
    int r[MAXSIZE + 1];    // r[0]用作哨兵或者临时变量
    int length;
} SqList;

/*
 * 排序算法
 *
 * 内排序：插入排序、交换排序、选择排序、归并排序
 * 外排序：
 * 简单算法：冒泡排序、简单选择排序、直接插入排序
 * 改进算法：希尔排序、堆排序、归并排序、快速排序
 */

/*
 * 交换L中数组r下标i和j的值
 */
static void swap (SqList *L, int i, int j) {
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

static void gennerateRandData (SqList *L) {
    srand(time(0));    // 产生随机数种子

    L->r[0] = -100;    // 哨兵
    L->length = MAXSIZE;
    for (int i = 1; i <= MAXSIZE; i++) {
        L->r[i] = rand() % 100 + 1;
    }
}

static void printData (SqList L) {
    for (int i = 1; i <= MAXSIZE; i++) {
        printf("printData index %d, data is %d ...\n", i, L.r[i]);
    }
}
