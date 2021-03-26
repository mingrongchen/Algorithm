//
// Created by MingR on 2021/3/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20    // 存储空间初始分配量

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];    // 数组存储数据元素
    int length;
} SqList;

/*
 * 用e返回L中第i个数据元素的值
 */
static Status GetElem (SqList L, int i, ElemType *e) {
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }

    *e = L.data[i - 1];

    return OK;
}

/*
 * 在L中第i个位置插入新的数据元素e，L的长度加1
 */
static Status ListInsert (SqList *L, int i, ElemType e) {
    int k;

    // 顺序线性表已经满
    if (L->length == MAXSIZE) {
        return ERROR;
    }

    // 插入的位置不在范围内时
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }

    // 若插入数据位置不在表尾
    if (i <= L->length) {
        // 将要插入位置之后的数据元素向后移动一位
        for (k = L->length - 1; k >= i - 1; k--) {
            L->data[k + 1] = L->data[k];
        } // for end
    }

    // 新元素插入，若在表尾插入，则直接写入
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

/*
 * 删除L的第i个数据元素，并用e返回其值，L的长度减一
 */
static Status ListDelete (SqList *L, int i, ElemType *e) {
    int k;

    // 线性表为空
    if (L->length == 0) {
        return ERROR;
    }

    // 删除位置不正确
    if (i < 1 || i > L->length) {
        return ERROR;
    }

    // 取出需要删除的元素
    *e = L->data[i - 1];

    if (i < L->length) {
        // 将删除位置后继元素前移
        for (k = i; k < L->length; k++) {
            L->data[k - 1] = L->data[k];
        } // for end
    }

    L->length--;
    return OK;
}

