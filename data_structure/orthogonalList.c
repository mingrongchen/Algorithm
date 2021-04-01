//
// Created by MingR on 2021/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * 十字链表(Orthogonal List)的定义
 */

typedef char VertexType;    // 顶点类型
typedef int EdgeType;    // 边上权值类型
#define MAXVEX 100    // 最大顶点数
#define MYINFINITY 65535    // 用65535代表∞