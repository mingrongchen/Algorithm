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
typedef int QElemType;

/*
 * 节点结构
 */
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

/*
 * 队列的链表结构
 */
typedef struct {
    QueuePtr front;    // 队头指针，包含头节点
    QueuePtr rear;
} LinkQueue;

/*
 * 入队操作，插入元素e为Q的新的队尾元素
 */
static Status EnQueue (LinkQueue *Q, QElemType e) {
    QueuePtr s = (QueuePtr) malloc(sizeof(QNode));

    // 存储分配失败
    if (!s) {
        exit(OVERFLOW);
    }

    // 新节点赋值
    s->data = e;
    s->next = NULL;

    Q->rear->next = s;    // 把拥有元素e的新节点s赋值给原队尾节点的后继
    Q->rear = s;    // 把当前的s设置为队尾节点，rear指向s

    return OK;
}

/*
 * 出队操作，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR
 */
static Status DeQueue (LinkQueue *Q, QElemType *e) {
    QueuePtr p;

    if (Q->front == Q->rear) {
        return ERROR;
    }

    p = Q->front->next;    // 第一个节点，将欲删除的队头节点暂存给p
    *e = p->data;    // 将第一个节点的值赋给e

    Q->front->next = p->next;    // 将原队头节点后继p->next赋值给头节点后继

    // 若队头是队尾，则删除后将rear指向头节点
    if (Q->rear == p) {
        Q->rear = Q->front;
    }
    free(p);

    return OK;
}
