//
// Created by MingR on 2021/6/25.
//

#include <stdio.h>
#include "queue.c"

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 10
#define MYINFINITY 65535
#define TRUE 1
#define FALSE -1

typedef int boolean;

int visited[MAXVEX];

// 定义边表节点, 一维链表
typedef struct EdgeNode {
    int adjvex;    // 邻接顶点
    EdgeType weight;    // 权重
    struct EdgeNode *next;
} EdgeNode;

// 定义顶点表节点
typedef struct VertexNode {
    int in;    // 入度
    VertexType data;    // 顶点域，存储顶点信息，定义为一个字符
    EdgeNode *firseNode;    // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;    // 顶点表数组
    int numVertexes;    // 定义顶点数
    int numEdges;       // 定义边数
} graphAdjList, *GraphAdjList;

/*
 * 邻接表的递归深度优先遍历
 * GL: 邻接表
 * i: 当前节点
 */
static void DFS(GraphAdjList GL, int i) {
    EdgeNode *p;
    visited[i] = TRUE;
    // 打印该节点的值
    printf("%c ", GL->adjList[i].data);

    p = GL->adjList[i].firseNode;    // 指向该点边表头节点

    while(p) {
        // 对访问的邻接顶点进行递归调用
        if (p && !visited[p->adjvex]) {
            DFS(GL, p->adjvex);
        }
        p= p->next;    // 指向邻接边表下一个邻接节点
    }
}

static void DFSTraverse(GraphAdjList GL) {
    int i;

    for (i = 0; i < GL->numVertexes; i++) {
        visited[i] = FALSE;
    }

    for (i = 0; i < GL->numVertexes; i++) {
        // 对未访问的顶点调用DFS，若是连通图，只会执行一次
        if (!visited[i]) {
            DFS(GL, i);
        }
    }
}

/**
 * 邻接表的广度优先遍历
 * @param GL
 */
static void BFSTraverse(GraphAdjList GL) {
    int i;
    Queue Q;
    EdgeNode *p;

    for (i = 0; i < GL->numVertexes; i++) {
        visited[i] = FALSE;
    }

    // 遍历所有节点
    for (i = 0; i < GL->numVertexes; i++) {
        // 如果该节点没有被访问
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c", GL->adjList[i].data);    // 打印该节点的值
            EnQueue(&Q, i);    // 把当前节点入队列

            while (!QueueEmpty(Q)) {

                DeQueue(&Q, &i);    // 节点出队，并将当前节点赋值给i

                p = GL->adjList[i].firseNode;    // 取出当前节点邻接点链表
                while (p) {
                    if (p && !visited[p->adjvex]) {
                        visited[p->adjvex] = TRUE;    // 当前节点访问位设置为TRUE
                        printf("%c ", GL->adjList[p->adjvex].data);    // 打印当前节点的值
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;    // 访问下一个邻接点
                }
            }
        }
    }
}


/**
 * 拓扑排序
 * @param GL
 */
static int TopoLogicSort(GraphAdjList GL) {
    EdgeNode *e;

    int i, k, gettop;
    int top = 0;    // 栈顶指针
    int count = 0;    // 输出顶点个数，用于统计是否有环，是否是DAG图（无环图）

    int *stack;
    stack = (int *)malloc(GL->numVertexes * sizeof(int));

    for (i = 0; i < GL->numVertexes; i++) {
        if (GL->adjList[i].in == 0) {
            // 将入度为0的顶点入栈
            stack[++top] = i;
        }
    }

    while (top != 0 ) {
        gettop = stack[top--];    // 出栈

        printf("%d -> ", GL->adjList[gettop].data);
        count++;

        // 出栈后将相邻顶点入度减一，再判断是否要入栈
        for (e=GL->adjList[gettop].firseNode; e; e=e->next){
            k = e->adjvex;

            // 将与栈顶顶点，即k号顶点的入度减一，再判断是否为0，为0则入栈
            if (!(--GL->adjList[k].in)) {
                stack[++top] = k;    // 若入度为0则入栈
            }
        }
    }

    // 若count数小于顶点数，说明有环
    if (count < GL->numVertexes) {
        return -1;
    } else {
        return 1;
    }
}

int *etv;    // 事件节点最早发生时间数组
int *ltv;    // 事件节点最晚发生时间数组
int *stack2;    // 存储拓扑序列的栈
int top2;    // 用于stack2的指针

/**
 * 关键路径算法的拓扑排序，求得拓扑排序和事件节点最早发生数组
 * @param GL
 */
static int TopoLogicSort_Two(GraphAdjList GL) {
    EdgeNode *e;    // 临时边集节点
    int i, k, gettop;
    int top = 0;    // 用于栈指针下标
    int count = 0;    // 用于统计输出顶点个数

    int *stack;    // 建栈将入度为0的节点入栈

    stack = (int *)malloc(GL->numVertexes * sizeof(int));

    for (i = 0; i < GL->numVertexes; i++) {
        if (GL->adjList[i].in == 0) {
            stack[++top] = i;
        }
    }

    top2 = 0;    // 初始化为0
    etv = (int *)malloc(GL->numVertexes * sizeof(int));    // 时间最早发生时间数组
    for (i = 0; i < GL->numVertexes; i++) {
        etv[i] = 0;
    }

    stack2 = (int *) malloc(GL->numVertexes * sizeof(int));

    while (top != 0) {
        gettop = stack[top--];
        count++;

        stack2[++top2] = gettop;    // 将弹出的顶点序号压入拓扑序列的栈

        for (e = GL->adjList[gettop].firseNode; e; e = e->next) {
            k = e->adjvex;    // 邻接下一个节点
            if (!(--GL->adjList[k].in)) {
                stack[++top] = k;
            }

            // 求各顶点事件最早发生时间值
            if ((etv[gettop] + e->weight) > etv[k]) {
                etv[k] = etv[gettop] + e->weight;
            }
        }
    }

    if (count < GL->numVertexes) {
        return -1;
    } else {
        return 1;
    }
}

/**
 * 求关键路径算法，求源点到汇点的最大长度
 * @param GL
 */
static void CriticalPath(GraphAdjList GL) {
    EdgeNode *e;
    int i, j, k, gettop;
    int ete;    // 活动边最早发生时间
    int lte;    // 活动边最晚发生时间

    TopoLogicSort_Two(GL);    // 求得拓扑序列，得到拓扑序列栈stack2和节点最早发生时间etv数组

    ltv = (int *) malloc(GL->numVertexes * sizeof(int));    // 事件节点最晚发生时间

    for (i = 0; i < GL->numVertexes; i++) {
        ltv[i] = etv[GL->numVertexes - 1];
    }

    // 计算事件节点最晚发生时间
    while (top2 != 0) {
        gettop = stack2[top2--];    // 将拓扑序列出栈，后进先出
        // 求各顶点事件最迟发生时间，从汇点到源点，从后往前
        for (e = GL->adjList[gettop].firseNode; e; e = e->next) {
           k = e->adjvex;

           if (ltv[k] - e->weight < ltv[gettop]) {
               ltv[k] = ltv[k] - e->weight;
           }
        }
    }

    // 已经求得事件节点最早发生时间etv和最晚发生时间ltv，计算关键路径
    for (i = 0; i < GL->numVertexes; i++) {
        for (e = GL->adjList[i].firseNode; e; e = e->next) {
            k = e->adjvex;

            ete = etv[i];    // 活动边最早发生时间
            lte = ltv[k] - e->weight;    // 活动边最迟发生时间
            // 如果活动边最早发生时间和最晚发生时间相等，则在关键路径上
            if (ete == lte) {
                printf("<v%d, v%d> length : %d , ",
                        GL->adjList[i].data, GL->adjList[k].data, e->weight);
            }
        }
    }
}


