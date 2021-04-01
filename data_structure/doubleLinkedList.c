//
// Created by MingR on 2021/3/29.
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

// 线性表的双向链表存储结构
typedef struct Node {
    ElemType data;
    struct Node *prior;    // 直接前驱指针
    struct Node *next;    // 直接后继指针
} DulNode, *DuLinkList;

/*
 * 插入
 * s->prior = p;    // 把p赋值给s的前驱
 * s->next = p->next;    // 把p->next赋值给s的后继
 *
 * p->next->prior = s;    // 把s赋值给p->next的前驱
 * p->next = s;    // 把s赋值给p的后继
 * */

/*
 * 删除
 * p->prior->next = p->next;    // 把p->next赋值给p->prior的后继
 * p->next->prior = p->prior;    // 把p->prior赋值给p->next的前驱
 * free(p);    // 释放节点
 */
