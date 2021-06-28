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





