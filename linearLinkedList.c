//
// Created by MingR on 2021/3/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20    // 存储空间初始分配量

typedef int Status;
typedef int ElemType;

// 线性表的单链表存储结构
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;

/*
 * 随机产生n个元素的值，建立带表头节点的单链线性表L（头插法）
 */
static void CreateListHead (LinkList *L, int n) {
    LinkList p;
    int i;

    srand(time(0));    // 初始化随机数种子

    *L = (LinkList) malloc(sizeof(Node));
    (*L)->next = NULL;    // 建立一个带头节点的单链表

    for (i = 0; i < n; i++) {
        p = (LinkList) malloc(sizeof(Node));    // 生成新节点
        p->data = rand() % 100 + 1;    // 随机生成100以内的数字

        p->next = (*L)->next;
        (*L)->next = p;    // 插入到表头
    }
}

static void CreateListTail (LinkList *L, int n) {
    LinkList p, r;
    int i;
    srand(time(0));    // 初始化随机数种子

    *L = (LinkList) malloc(sizeof(Node));    // 为整个线性表
    r = *L;    // r为指向尾部的节点

    for (i = 0; i < n; i++) {
        p = (LinkList) malloc(sizeof(Node));    // 生成新结点
        p ->data = rand() % 100 + 1;    // 随机生成100以内的数字

        r->next =p;    // 将表尾终端节点的指针指向新节点
        r = p;    // 将当前的新节点定义为表尾终端节点
    } // end

    r->next = NULL;    // 表示当前链表结束
}


/*
 * 单链表读取，获取单链表L中第i个数据元素的值
 */
static Status GetElem (LinkList L, int i, ElemType *e) {
    int j;
    LinkList p;    // 声明节点指针
    p = L->next;    // 让p指向链表L的第一个节点
    j = 1;    // j为计数器

    /*
     * p不为空或者计数器还没有等于i时，循环继续
     * 寻找第i个数据元素的位置
     */
    while (p && j < i) {
        p = p->next;    // p指向下一个节点
        ++j;    // 若找到，j等于i的值，p从第一个节点开始，则p代表第i个节点的指针
    }

    // 第i个元素不存在
    if (!p || j > i) {
        return  ERROR;
    }

    *e = p->data;    // 取第i个元素的数据

    return OK;
}

/*
 * 在线性链表L中第i个位置之前插入新的数据元素e，L的长度加1
 */
static Status ListInsert(LinkList *L, int i, ElemType e) {
    int j;
    LinkList p, s;    // 节点指针，p代表待插入节点的前驱指针, s代表待插入节点指针

    p = *L;    // p指向链表头，而非链表第一个节点
    j = 1;

    // 寻找第i个节点
    while (p && j < i) {
        p = p->next;
        ++j;    // 若找到，则j等于i的值，p从头节点开始，则p代表第i-1个节点的指针
    }

    // 第i个元素不存在，返回错误
    if (!p || j > i) {
        return ERROR;
    }

    // 找到插入i节点的位置后，生成新的节点
    s = (LinkList) malloc(sizeof(Node));
    s->data = e;
    /*
     * p指向第i-1个位置
     * 将p的后继i，放入s之后，则变成后继i+1
     * 将s放入p之后，变成后继i
     */
    s->next = p->next;    // 将p的后继节点赋值给s的后继
    p->next = s;    // 将s赋值给p的后继

    return OK;
}

/*
 * 删除线性表L中第i个节点，并用e返回其值，L的长度减一
 */
static Status ListDelete (LinkList *L, int i, ElemType *e) {
    int j;
    LinkList p, q;    // 节点指针，p代表待删除节点的前驱指针, q代表待删除节点指针
    p = *L;    // p指向头节点

    // 遍历寻找第i-1个元素
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }

    // 第i个元素不存在
    if (!(p->next) || j > i) {
        return ERROR;
    }

    q = p->next;
    p->next = q->next;    // 将q的后继赋值给p的后继
    *e = q->data;    // 将q节点中的数据赋值给e

    free(q);    // 让系统回收此节点，并释放内存

    return OK;
}

/*
 * 顺序线性表L已存在，操作结果，将L重置为空表
 */
static Status ClearList (LinkList *L) {
    LinkList p, q;    // 每次释放当前指针，需要找到当前指针的下一个位置，然后重复操作释放
    p = (*L)->next;    // p指向第一个节点

    while (p) {
        q = p->next;
        free(p);
        p = q;
    }

    (*L)->next = NULL;    // 头节点指针域为空
    return OK;
}
