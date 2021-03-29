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

// 线性表的单链表存储结构
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;

