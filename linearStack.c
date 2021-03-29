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
typedef int SElemType;

typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;

static Status StackEmpty(LinkStack S) {
    if (S.count <= 0) {
        return TRUE;
    }

    return FALSE;
}

/*
 * 插入元素e为新的栈顶元素
 */
static Status Push (LinkStack *S, SElemType e) {
    LinkStackPtr s = (LinkStackPtr) malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;    // 将当前栈顶元素赋值给新节点的直接后继

    S->top = s;    // 将新的节点s赋值给栈顶指针
    S->count++;

    return OK;
}

/*
 * 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
 */
static Status Pop (LinkStack *S, SElemType *e) {
    LinkStackPtr p;

    if (StackEmpty(*S)) {
        return ERROR;
    }

    *e = S->top->data;
    p = S->top;    // 将栈顶节点赋值给p
    S->top = S->top->next;    // 使得栈顶指针下移一位，指向后一节点
    free(p);    // 释放节点p

    S->count--;

    return OK;
}