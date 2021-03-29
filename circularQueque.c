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
 * 循环队列的顺序存储结构
 */
typedef struct {
    QElemType data[MAXSIZE];
    int front;    // 头指针
    int rear;    // 尾指针，若队列不空，指向队列元素的下一个位置
} SqQueue;

/*
 * 循环队列的初始化代码
 */
static Status InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/*
 * 返回Q的元素个数，也就是当前队列长度
 */
static int QueueLength (SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/*
 * 循环队列入队操作
 * 若队列未满，则插入元素e为Q新的队尾元素
 */
static Status EnQueue (SqQueue *Q, QElemType e) {
    // 判断队列满
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        return ERROR;
    }

    Q->data[Q->rear] = e;    // 将元素e赋值给队尾
    Q->rear = (Q->rear + 1) % MAXSIZE;    // rear指针后移一位置

    return OK;
}

/*
 * 循环队列出队操作
 * 若队列不为空，则删除Q中队头元素，用e返回其值
 */
static Status DeQueue (SqQueue *Q, QElemType *e) {
    // 队列空的判断
    if (Q->front == Q->rear) {
        return ERROR;
    }

    *e = Q->data[Q->front];    // 将队头元素赋值给e
    Q->front = (Q->front + 1) % MAXSIZE;    // front指针后移一位

    return OK;
}
