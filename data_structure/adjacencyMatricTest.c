//
// Created by MingR on 2021/6/25.
//

#include <stdio.h>
#include "queue.c"

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 9
#define MYINFINITY 65535

typedef int boolean;
#define FALSE -1
#define TRUE 1
EdgeType visited[MAXVEX];    // 节点是否访问数组

typedef struct {
    VertexType vertexes[MAXVEX];
    EdgeType arcs[MAXVEX][MAXVEX];

    int numVertexes;
    int numEdges;
} MGraph;

/* 邻接矩阵深度优先算法，类似树的前序遍历，利用回溯方法
 * G：邻接表
 * i: 图当前节点
 */
static void DFS(MGraph G, int i) {
    int j;
    visited[i] = TRUE;    // 将访问节点置为已访问
    printf("%c ", G.vertexes[i]);    // 打印顶点

    for (j = 0; j < G.numVertexes; j++) {
        // 顶点邻接边存在，且邻接顶点未被访问
        if (G.arcs[i][j] == 1 && !visited[j]) {
            DFS(G, j);    // 对访问邻接顶点递归调用
        }
    }
}

static void DFSTraverse(MGraph G) {
    int i;

    // 初始化所有顶点状态均未访问
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }

    for (i = 0; i < G.numVertexes; i++) {
        // 对未访问节点调用DFS，若连通图则只执行一次
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

/* 邻接矩阵广度优先算法，利用队列方法
 *
 */
static void BFSTraverse(MGraph G) {
    int i, j;
    Queue Q;    // 队列

    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }

    InitQueue(&Q);    // 辅助队列初始化

    // 对每个顶点做循环
    for (i = 0; i < G.numVertexes; i++) {
        // 当前节点没有被访问过，进行处理
        if (!visited[i]) {
            visited[i] = TRUE;    // 当前节点设置为已访问

            printf("%c ", G.vertexes[i]);    // 打印节点

            EnQueue(&Q, i);    // 将该节点入队列
            // 当前队列不为空时
            while(!QueueEmpty(Q)) {
                DeQueue(&Q, &i);    // 队列出队，将队列头节点赋值给i

                // 遍历邻接矩阵，寻找与节点i相邻的顶点
                for (j = 0; j < G.numVertexes; j++) {

                    // 寻找与节点i相邻的点，并且该节点未被访问过
                    if(G.arcs[i][j] == 1 && !visited[j]) {
                        visited[j] = TRUE;    // 找到相邻节点，并设置为已访问
                        printf("%c ", G.vertexes[j]);    // 打印该节点
                        EnQueue(&Q, j);    // 找到该节点并将该节点入队列
                    }
                }
            }
        }
    }
}

/**
 * 最小生成树算法，Prim算法，动态规划
 * @param G
 */
static void MiniSpanTree_Prim(MGraph G) {
    int i, j, k, min;

    int adjVex[MAXVEX];    // 表示与i节点相邻的节点
    int lowCost[MAXVEX];    // 表示最小生成树的边，动态规划，不断更新

    // 初始化
    adjVex[0] = 0;
    lowCost[0] = 0;

    for (i = 1; i < G.numVertexes; i++) {
        lowCost[i] = G.arcs[0][i];    // 初始化最小生成树边集
        adjVex[i] = 0;    // 将v0节点外的下标全设置为v0
    }

    // 循环遍历剩下节点
    for (i = 1; i < G.numVertexes; i++) {
        min = INFINITY;

        k = 0;
        for (j = 1; j < G.numVertexes; j++) {
            if (lowCost[j] != 0 && lowCost[j] < min) {
                min = lowCost[j];    // 更新该节点与当前树的最小距离，目的寻找最小距离
                k = j;    // 保存与当前树最小距离的节点位置
            }
        }

        printf("(%d, %d)", adjVex[k], k);    // 打印当前顶点边中最小边
        lowCost[k] = 0;    // 将k节点加入最小生成树中

        // 更新状态
        for (j = 1; j < G.numVertexes; j++) {
            // 检查与新节点k相邻点到树的距离，若小于该节点保存值则更新
            if (lowCost[j] != 0 && G.arcs[k][j] < lowCost[j]) {
                lowCost[j] = G.arcs[k][j];    // 更新其他节点与最小生成树的距离
                adjVex[j] = k;    // 更新最小生成树与k节点相邻的节点
            }
        }
    }
}


/**
 * 并查集查找根节点，并压缩路径
 * @param parents
 * @param x
 */
static int findRoot(int *parents, int x) {

    int root;
    // 查找并查集根节点位置
    while (parents[root] != root) {
        root = parents[root];
    }

    // 路径压缩
    int i = x;
    int j;

    // 当当前节点不是根节点时，改变当前节点为根节点
    while (i != root) {
        j = parents[i];    // 保存当前节点的值，即下一个节点的位置
        parents[i] = root;
        i = j;    // 查找下一个节点
    }

    return root;
}

/**
 * 并查集寻找根
 * @param parents
 * @param x
 * @return
 */
static int find(int *parents, int x) {
    while (parents[x] > 0) {
        x = parents[x];
    }

    return x;
}

#define MAXEDGE 20
typedef struct {
    int begin;
    int end;
    int weight;
} Edge;

static void MiniSpanTree_kruskal(MGraph G) {
    int i, n, m;
    Edge edges[MAXEDGE];    // 定义边集数组
    int parents[MAXVEX];    // 定义一数组判断边与边是否包含回路

    // 省略边集数组从小到大排序步骤

    // 初始parents数组
    for (i = 0; i < G.numVertexes; i++) {
        parents[i] = 0;
    }

    for (i = 0; i < G.numEdges; i++) {
        n = find(parents, edges[i].begin);
        m = find(parents, edges[i].end);

        if (n != m) {    // 说明没有环路，将此边结尾顶点放入下标为起点的parent中
            parents[n] = m;
            printf("(%d, %d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}
