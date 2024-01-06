#include <stdio.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 9
#define MYINFINITY 65535

typedef struct {
    VertexType vertexes[MAXVEX];
    EdgeType arcs[MAXVEX][MAXVEX];

    int numVertexes;
    int numEdges;
} MGraph;

typedef int boolean;
#define FALSE -1
#define TRUE 1
EdgeType visited[MAXVEX];    // 节点是否访问数组


/* 邻接矩阵深度优先算法
 * G：邻接表
 * i: 图节点
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


/* 邻接矩阵深度优先算法
 * G：邻接表
 * i: 图节点
 */
static void DFS2(MGraph G, int i) {
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


static void test() {
    printf("Test begin ...");

    int n = 100;
    for (int i = 1; i < n ; ) {
        i = i * 2;
    }

    if (0) {
        printf("0");
    } else {
        printf("1");
    }


}