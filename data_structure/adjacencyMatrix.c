//
// Created by MingR on 2021/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.c"

/**
 * 邻接矩阵(Adjacency Matrix)的定义
 */

typedef char VertexType;    // 顶点类型
typedef int EdgeType;    // 边上权值类型
//#define MAXVEX 100    // 最大顶点数
#define MAXVEX 9    // 最大顶点数
#define MYINFINITY 65535    // 用65535代表∞

typedef struct {
    VertexType vexs[MAXVEX];    // 顶点表
    EdgeType  arc[MAXVEX][MAXVEX];    // 邻接矩阵
    // 图中当前顶点数和边数
    int numVertexes;
    int numEdges;
} MGraph;

// 建立无向网图的邻接矩阵表示
static void CreateMGraph(MGraph *G) {
    int i, j, k, w;

    printf("输入顶点数和变数:\n");
    scanf("%d,%d",G->numVertexes, G->numEdges);    // 输入顶点数和边数

    for (i = 0; i < G->numVertexes; i++) {    // 输入顶点信息，建立顶点表
        scanf(&G->vexs[i]);
    }

    // 邻接矩阵初始化
    for (i = 0; i < G->numVertexes; i++){
        for (j = 0; j < G->numVertexes; j++) {
            G->arc[i][j] = MYINFINITY;
        }
    }

    // 读入numEdges条边，建立邻接矩阵
    for (k = 0; k < G->numEdges; k++) {
        printf("输入边（vi，vj）上的下标i，下标j和权:\n");
        scanf("%d, %d, %d", &i, &j, &w);    // 输入边（vi，vj）上的权w
        G->arc[i][j] = w;
        G->arc[i][j] = G->arc[j][i];    // 因为是无向图，矩阵对称
    } // CreateMGraph end
}

#define MAX 100
#define TRUE 1
#define FALSE 0
typedef int Boolean;    // 布尔类型，其值是TRUE或FALSE
Boolean visited[MAX];    // 访问标志的数组

/*
 * 邻接矩阵的深度优先递归算法
 * 类似树的前序遍历
 * 使用算法：回溯法
 */
static void DFS(MGraph G, int i) {
    int j;
    visited[i] = TRUE;
    printf("%c ", G.vexs[i]);    // 打印顶点，也可以是其它操作

    for (j = 0; j < G.numVertexes; j++) {
        // 判断其它顶点若与当前顶点存在边且访问过
        if (G.arc[i][j] == 1 && !visited[j]) {
            DFS(G, j);    // 对为访问的邻接顶点递归调用
        }

    }
}

/*
 * 邻接矩阵的深度遍历操作
 */

static void DFSTraverse (MGraph G) {
    int i = 0;

    // 初始所有顶点状态都是未访问过的状态
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }

    for (i = 0; i < G.numVertexes; i++) {
        // 对未访问过的顶点调用DFS，若是连通图，只会执行一次
        if (!visited[i]){
            DFS(G, i);
        }
    }
}

/*
 * 邻接矩阵的广度遍历算法
 * 类似层次遍历
 */

static void BFSTraverse (MGraph G) {
    int i, j;
    Queue Q;

    // 初始所有顶点状态都是未访问过的状态
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }

    // 初始化一辅助用的队列
    InitQueue(&Q);

    // 对每一个顶点做循环
    for (i = 0; i < G.numVertexes; i++) {
        // 若是没有访问过就处理
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", G.vexs[i]);    // 打印顶点，也可以是其它操作
            EnQueue(&Q, i);    // 将顶点入队列

            // 当队列不为空
            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &i);    // 将队中元素出队列，赋值给i

                for (j = 0; j < G.numVertexes; j++) {
                    // 判断其它顶点若与当前顶点存在边且访问过
                    if (G.arc[i][j] == 1 && !visited[j]) {
                        visited[j] = TRUE;    // 将找到此顶点标记为已访问
                        printf("%c ", G.vexs[j]);    // 打印顶点
                        EnQueue(&Q, j);    // 将找到的此顶点入队列
                    }
                } // for end
            } // while end
        }
    } // for end
} // BFSTraverse end

/*
 * 最小生成树（Minimum Cost Spanning Tree）
 * Prim算法生成最小生成树
 * 以顶点为起点
 * 时间复杂度n的平方
 * 动态规划算法
 */
static void MiniSpanTree_Prim(MGraph G) {
    int min, i, j, k;

    int adjvex[MAXVEX];    // 保存与i顶点相邻边的顶点序号
    int lowcost[MAXVEX];    // 表示最小生成树的边，保存相关顶点间边的权值，不断更新，当前节点到树的距离

    /*
     * 初始化第一个权值为0，即v0加入生成树
     * lowcost的值为0，在这里就是此下标的顶点已经加入生成树
     */
    lowcost[0] = 0;
    adjvex[0] = 0;    // 初始化第一个顶点下标为0

    // 循环除下标为0外的全部顶点
    for (i = 1; i < G.numVertexes; i++) {
        lowcost[i] = G.arc[0][i];    // 将v0顶点与之有边的权值存入数组
        adjvex[i] = 0;    // 初始化都为v0的下标
    }

    // 构造最小生成树过程
    for (int i = 1; i < G.numVertexes; i++) {
        min = MYINFINITY;    // 初始化最小权值为∞

        j = 1;    // 顶点下标循环的变量
        k = 0;    // 存储最小权值顶点的下标

        // 循环全部顶点
        while (j < G.numVertexes) {
            // 如果权值不为0（顶点不参与查找）且权值小于min
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];    // 则让当前权值成为最小值
                k = j;    // 将当前最小值的下标存入k
            }
            j++;
        }

        printf("(%d, %d)", adjvex[k], k);    // 打印当前顶点边中最小边
        lowcost[k] = 0;    // 将当前顶点的权值设置为0, 表示此顶点已经完成任务

        // 循环所有顶点
        for (j = 1; j < G.numVertexes; j++) {
            // 若下标为k的顶点各边权值小于此前这些顶点未被加入生成树权值
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                lowcost[j] = G.arc[k][j];    // 将较小权值存入lowcost
                adjvex[j] = k;    // 将下标为k的顶点存入adjvex
            }
        } // for end
    } // for end

} // MinSpanTree_Prim end

/*
 * Kruskal算法
 * 以边为目标构建
 * 时间复杂度eloge
 */

#define MAXEDGE 20    // 最大边集数

// 边集数组Edge结构定义
typedef struct {
    int begin;
    int end;
    int weight;
} Edge;

// 查找连线顶点的尾部下标
static int Find(int *parent, int f) {
    while (parent[f] > 0) {
        f = parent[f];
    }
    return f;
}

// Kruscal算法最小生成树
static void MiniSpanTree_Kruskal (MGraph G) {
    int i ,n ,m;
    Edge edges[MAXEDGE];    // 定义边集数组
    int parent[MAXVEX];    // 定义一数组来判断边与边是否形成环路，并查集
    // 此处省略将邻接矩阵G转化为边集数组edges并按权由小到大排序的代码

    for (i = 0; i < G.numVertexes; i++) {
        parent[i] = 0;    // 根节点为0，设置其他节点的根节点为0
    }

    // 循环每一条边, 边数numEdge
    for (i = 0; i < G.numEdges; i++) {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);

        // 假如n与m不等，说明此边没有与现有生成树形成环路
        if (n != m) {
            /*
             * 将此边的结尾顶点放入下标为起点的parent中
             * 表示此顶点已经在生成树集合中
             */
            parent[n] = m;
            printf("(%d, %d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
        }
    } // for end
} //MiniSpanTree_Kruscal end


typedef int PathArc[MAXVEX];    // 用于存储最短路径下标的数组，表示最短路径前驱，例v0->v1->v3则存储为1
typedef int ShortPathTable[MAXVEX];    // 用于存储到各点最短路径的权值和

/*
 * Dijkstra算法，求有向网G的v0顶点到其余顶点v最短路径P[v]及带权长度D[v]
 * P[v]的值为前驱顶点下标，D[v]表示v0到v最短路径长度和
 * 时间复杂度为n的三次方
 *
 * 使用算法：贪心算法。
 */

static void ShortestPath_Dijkstra (MGraph G, int v0, PathArc *P, ShortPathTable *D) {
    int v, w, k, min;

    int final[MAXVEX];    // final[w]=1表示求得顶点v0至vw的最短路径，设置为1标记找到

    // 初始化数据
    for (v = 0; v < G.numVertexes; v++) {
        final[v] = 0;    // 全部顶点初始化为未知最短路径状态
        (*D)[v] = G.arc[v0][v];    // 将与v0点有连线的顶点加上权值
        (*P)[v] = 0;    // 初始化路径数组P为0
    }

    (*D)[v0] = 0;    // v0至v0的路径为0
    final[v0] = 1;    // v0至v0不需要求路径

    // 开始主循环，每次求得v0到某个v顶点的最短路径，因此v从1开始而不是从0开始
    for (v = 1; v < G.numVertexes; v++) {
        min = MYINFINITY;    // 当前所知离v0顶点的最近距离


        // 遍历该顶点所有边连接顶点距离，寻找离起点v0最近的顶点
        for (w = 0; w < G.numVertexes; w++) {
            if (!final[w] && (*D)[w] < min) {
                k = w;    // 找到w顶点
                min = (*D)[w];    // w顶点离起点v0顶点更近
            }
        }

        final[k] = 1;    // 将目前找到的最近的顶点置为1，加入最短路径

        // 更新当前节点连接节点的，最短路径及距离，关键★★★
        for (w = 0; w < G.numVertexes; w++) {
            /*
             * 如果经过v顶点的路径比现在这条路径的长度短的话
             * 说明找到了更短路径，修改D[w]和P[w]
             */
            if (!final[w] && (min + G.arc[k][w] < (*D)[w])) {
                (*D)[w] = min + G.arc[k][w];    // 修改当前最短路径长度
                (*P)[w] = k;    // 修改当前最短路径前驱节点
            }

        } // for end
    } // for end
} // ShortestPath_Dijkstra end


typedef int FPathArc[MAXVEX][MAXVEX];    // 用于存储最短路径下标的数组，代表对应顶点的最小路径的前驱矩阵
typedef int FShortPathTable[MAXVEX][MAXVEX];    // 用于存储到各点最短路径的权值和，代表顶点到顶点的最短路径权值和的矩阵

/*
 * Floyd 算法，求网图G中各顶点v到其余顶点w最短路径P[v][w]及带权长度D[v][w]
 */
static void ShortestPath_Floyd (MGraph G, FPathArc *P, FShortPathTable *D) {
    int v, w, k;

    // 初始化D与P
    for (v = 0; v < G.numVertexes; v++) {
        for (w = 0; w < G.numVertexes; w++) {
            (*D)[v][w] = G.arc[v][w];    // D[b][w]值即为对应点间的权值
            (*P)[v][w] = w;    // 初始化P
        } // for end
    } // for end

    /*
     * k：代表中转顶点的下标，也就是所有顶点经过v(?)中转，计算是否有最短路径的变化
     * v：代表起始顶点
     * w: 代表结束顶点
     */
    for (k = 0; k < G.numVertexes; k++) {
        for (v = 0; v < G.numVertexes; v++) {
            for (w = 0; w < G.numVertexes; w++) {
                /*
                 * 如果经过下标为k顶点路径比原两点间路径更短
                 * 将当前两点间权值设为更小的一个
                 */
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];    // 替换v->w的最短路径长度，经过k中转
                    (*P)[v][w] = (*P)[v][k];    // 路径设置经过下标为k的顶点
                }
            } // for end
        } // for end
    } // for end
} // ShortestPath_Floyd end

/*
 * 求最短路径显示代码如下，对
 */

static void show_floyd (MGraph G, FPathArc *P, FShortPathTable *D) {
    int v, w, k;

    for (v = 0; v < G.numVertexes; ++v) {
        for (w = v + 1; w < G.numVertexes; w++) {
            printf("v%d-v%d weight: %d ", v, w, D[v][w]);

            k = P[v][w];    // 获得第一个路径顶点下标，例如v0->v1，则该k值为1
            printf(" path : %d ", v);    // 打印源点

            // 如果路径顶点下标不是终点
            while (k != w) {
                printf(" -> %d ", k);    // 打印路径顶点
                k = P[k][w];    // 获得下一个路径顶点下标
            } // while end

            printf(" -> %d\n", w);    // 打印终点
        } // for end
        printf("\n");
    } // for end
}