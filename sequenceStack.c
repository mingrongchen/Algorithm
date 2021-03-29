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

typedef struct {
    SElemType data[MAXSIZE];
    int top;    // 用于栈顶指针
} SqStack;

/*
 * 进栈操作。
 */
static Status Push (SqStack *S, SElemType e) {
    // 栈满
    if (S->top == MAXSIZE - 1) {
        return ERROR;
    }

    S->top++;    // 栈顶指针加一
    S->data[S->top] = e;    // 将新插入元素赋值给栈顶空间

    return OK;
}
/*
 * 出栈操作
 */
static Status Pop (SqStack *S, SElemType *e) {
    if (S->top == -1) {
        return ERROR;
    }

    *e = S->data[S->top];    // 将要删除的栈顶元素赋值给e
    S->top--;    // 将栈顶指针减一

    return OK;
}
