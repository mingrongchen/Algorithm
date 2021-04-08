//
// Created by MingR on 2021/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.c"

/**
 * 邻接表(Adjacency List)的定义
 */

typedef char VertexType;    // 顶点类型
typedef int EdgeType;    // 边上权值类型
#define MAXVEX 100    // 最大顶点数
#define MYINFINITY 65535    // 用65535代表∞

// 边表节点
typedef struct EdgeNode {
    int adjvex;    // 邻接点域，存储该顶点对应的下标
    EdgeType  weight;    // 存储权值，对于非网图可以不需要
    struct EdgeNode *next;    // 链域，指向下一个邻接点
} EdgeNode;

// 顶点表节点
typedef struct VertexNode {
    int in;    // 顶点入度
    int data;
//    VertexType data;    // 顶点域，存储顶点信息
    EdgeNode *firstedge;    // 边表头指针
} VertexNode, AdjList[MAXVEX];

// 邻接表
typedef struct {
    AdjList adjList;
    int numVertexes;
    int numEdges;
} graphAdjList, *GraphAdjList;

// 建立图的邻接表结构
static void CreateALGraph (GraphAdjList G) {
    int i, j, k, w;
    EdgeNode *e;

    printf("输入顶点数和变数:\n");
    // 输入顶点数和边数
    scanf("%d,%d",G->numVertexes, G->numEdges);

    // 输入顶点信息，建立顶点表
    for (i = 0; i < G->numVertexes; i++) {
        scanf(&G->adjList[i].data);    // 输入顶点信息
        G->adjList[i].firstedge = NULL;
    }

    // 建立边表
    for (k = 0; k < G->numEdges; k++) {
        printf("输入边（vi，vj）上的顶点序号:\n");
        scanf("%d, %d", &i, &j);    // 输入边（vi，vj）上的顶点序号

        // 边表链表使用头插法的方式
        e = (EdgeNode *) malloc(sizeof(EdgeNode));

        // 生成边表节点
        e->adjvex = j;    // 邻接序号为j
        e->next = G->adjList[i].firstedge;    // 将e指针指向当前顶点指向的节点
        G->adjList[i].firstedge = e;    // 将当前节点的指针指向e

        e = (EdgeNode *) malloc(sizeof(EdgeNode));

        // 生成边表节点
        e->adjvex = i;    // 邻接序号为i
        e->next = G->adjList[j].firstedge;    // 将e指针指向当前顶点指向的节点
        G->adjList[j].firstedge = e;    // 将当前节点的指针指向e
    }

} //CreateALGpaph end


#define MAX 100
#define TRUE 1
#define FALSE 0
typedef int Boolean;    // 布尔类型，其值是TRUE或FALSE
Boolean visited[MAX];    // 访问标志的数组

// 邻接表的深度优先递归算法
static void DFS(GraphAdjList GL, int i) {
    EdgeNode *p;

    visited[i] = TRUE;
    printf("%c ", GL->adjList[i].data);    // 打印顶点，也可以是其它操作

    p = GL->adjList[i].firstedge;

    while (p) {
        if (!visited[p->adjvex]) {
            DFS(GL, p->adjvex);    // 对为访问的邻接顶点递归调用
        }
        p->next;
    }
}

// 邻接表的深度遍历操作
void DFSTraverse (GraphAdjList GL) {
    int i = 0;

    // 初始所有顶点状态都是未访问过的状态
    for (i = 0; i < GL->numVertexes; i++) {
        visited[i] = FALSE;
    }

    for (i = 0; i < GL->numVertexes; i++) {
        // 对未访问过的顶点调用DFS，若是连通图，只会执行一次
        if (!visited[i]){
            DFS(GL, i);
        }
    }
}

/*
 * 邻接矩阵的广度遍历算法
 * 类似层次遍历
 */

static void BFSTraverse (GraphAdjList GL) {
    int i, j;
    EdgeNode *p;
    Queue Q;

    // 初始所有顶点状态都是未访问过的状态
    for (i = 0; i < GL->numVertexes; i++) {
        visited[i] = FALSE;
    }

    // 初始化一辅助用的队列
    InitQueue(&Q);

    // 对每一个顶点做循环
    for (i = 0; i < GL->numVertexes; i++) {
        // 若是没有访问过就处理
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", GL->adjList[i].data);    // 打印顶点，也可以是其它操作
            EnQueue(&Q, i);    // 将顶点入队列

            // 当队列不为空
            while (!QueueEmpty(Q)) {
                DeQueue(&Q, &i);    // 将队中元素出队列，赋值给i
                p = GL->adjList[i].firstedge;    // 找到当前顶点边表链表头指针

                for (;p;) {
                    // 若此顶点未被访问
                    if (!visited[p->adjvex]) {
                        visited[j] = TRUE;    // 将找到此顶点标记为已访问
                        printf("%c ", GL->adjList[p->adjvex].data);    // 打印顶点
                        EnQueue(&Q, p->adjvex);    // 将找到的此顶点入队列
                    }
                    p = p->next;    // 指针指向下一个邻接点
                } // for end
            } // while end
        }
    } // for end
} // BFSTraverse end

/*
 * 拓扑排序，若GL无回路，则输出拓扑排序序列并返回OK，若有回路返回ERROR
 *
 * 解决的问题：工程是否顺利进行
 *
 * AOV网(Activity On Vertex Network)：表示工程的有向图中，顶点表示活动，
 * 用弧表示活动之间的优先关系，这样的有向图为顶点表示活动的网。
 *
 * 拓扑序列：有向图G=(V,E)，满足从vi到vj一条路径，则在顶点序列中顶点vi必须在vj之前。
 *
 * 使用数据结构：栈
 *
 * 时间复杂度：O(n+e)，e表示入度减一操作的次数
 */
static int TopologicalSort (GraphAdjList GL) {
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;    // 用于栈指针下标
    int count = 0;    // 用于统计输出顶点的个数
    int *stack;    // 建栈存储入度为0的顶点

    stack = (int *) malloc(GL->numVertexes * sizeof(int));

    for (i = 0; i < GL->numVertexes; i++) {
        if (GL->adjList[i].in == 0) {
            stack[++top] = i;    // 将入度为0的顶点入栈
        }
    } // for end

    while (top != 0) {
        gettop = stack[top--];    // 出栈
        printf("%d -> ", GL->adjList[gettop].data);    // 打印此顶点
        count++;    // 统计输出顶点数

        // 对此顶点弧表遍历
        for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
            k = e->adjvex;
            // 将k号顶点邻接点的入度减1
            if (!(--GL->adjList[k].in)) {
                // 若入度为0则入栈，以便下次循环输出
                stack[++top] = k;
            }
        } // for end
    } // while end

    // 如果count小于顶点数，说明存在环
    if (count < GL->numVertexes) {
        return -1;
    } else {
        return 1;
    }
} // TopologicalSort end

/*
 * 拓扑排序，用于关键路径计算，关键路径长度（从源点到汇点具有最大长度的路径）
 * 若GL无回路，则输出拓扑排序序列并返回OK，若有回路返回ERROR
 *
 * 解决的问题：工程是否顺利进行，还要解决工程完成需要的最短时间问题
 *
 * AOE网(Activity On Edge Network):表示工程的带权有向图中，顶点表示事件，有向边表示活动，
 * 边上权重表示活动持续时间，这种网图称为AOE网
 *
 * 源点(始点)：没有入边，汇点(终点）：没有出边。一个工程只有一个源点一个汇点。
 *
 * 概念：找到所有活动最早开始时间和最晚开始时间，如果相等则为关键活动，活动间的路径为关键路径。
 * 1、节点事件最早发生时间etv(earliest time of vertex)：顶点vk最早发生的时间
 * 2、节点事件最晚发生时间ltv(latest time of vertex)：顶点vk最晚发生时间，也就是最晚需要开始的时间，
 * 超出则会延误整个工期。
 * 3、活动最早开工时间ete(earliest time of edge)：即弧ak的最早发生时间
 * 4、活动最晚开工时间lte(lastest time of edge)：即弧ak最晚发生时间，就是不推迟工期的最晚开工时间
 * 备注：由1和2可以求得3和4，然后根据ete[k]是否与lte[k]相等来判断ak是否是关键活动。
 *
 */
int *etv, *ltv;    // 事件最早发生时间和最迟发生时间数组
int *stack2;    // 用于存储拓扑序列的栈
int top2;    // 用于stack2的指针

static int TopologicalSort_Two (GraphAdjList GL) {
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;    // 用于栈指针下标
    int count = 0;    // 用于统计输出顶点的个数
    int *stack;    // 建栈存储入度为0的顶点

    stack = (int *) malloc(GL->numVertexes * sizeof(int));

    for (i = 0; i < GL->numVertexes; i++) {
        if (GL->adjList[i].in == 0) {
            stack[++top] = i;    // 将入度为0的顶点入栈
        }
    } // for end

    /*--------------start------------------*/
    top2 = 0;    // 初始化为0
    etv = (int *) malloc(GL->numVertexes * sizeof(int));    // 事件最早发生时间

    for (i = 0; i < GL->numVertexes; i++) {
        etv[i] = 0;
    }

    stack2 = (int *) malloc(GL->numVertexes * sizeof(int));    // 初始化
    /*---------------end-----------------*/

    while (top != 0) {
        gettop = stack[top--];    // 出栈
//        printf("%d -> ", GL->adjList[gettop].data);    // 打印此顶点
        count++;    // 统计输出顶点数
        /*------------start--------------------*/
        stack2[++top2] = gettop;    // 将弹出的顶点序号压入拓扑序列的栈
        /*-------------end-------------------*/

        // 对此顶点弧表遍历
        for (e = GL->adjList[gettop].firstedge; e; e = e->next) {
            k = e->adjvex;
            // 将k号顶点邻接点的入度减1
            if (!(--GL->adjList[k].in)) {
                // 若入度为0则入栈，以便下次循环输出
                stack[++top] = k;
            }

            /*--------------start------------------*/
            // 求各顶点事件最早发生时间值
            if ((etv[gettop] + e->weight) > etv[k]) {
                etv[k] = etv[gettop] + e->weight;
            }
            /*---------------end-----------------*/

        } // for end
    } // while end

    // 如果count小于顶点数，说明存在环
    if (count < GL->numVertexes) {
        return -1;
    } else {
        return 1;
    }
} // TopologicalSort end

/*
 * 求关键路径，GL为有向网，输出GL的各项关键活动
 */
static void CriticalPath (GraphAdjList GL) {
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;    // 声明活动最早发生时间和最迟发生时间变量
    TopologicalSort_Two(GL);    // 求拓扑序列，计算数组etv和stack2的值

    ltv = (int *) malloc(GL->numVertexes * sizeof(int));    // 事件最晚发生时间

    for (i = 0; i < GL->numVertexes; i++) {
        ltv[i] = etv[GL->numVertexes - 1];    // 初始化ltv
    }

    // 计算ltv
    while (top2 != 0) {
        gettop = stack2[top2--];    // 将拓扑序列出栈，先进先出
        // 求各顶点事件的最迟发生时间ltv的值
        for (e = GL->adjList[gettop].firstedge; e; e->next) {
            k = e->adjvex;
            // 求各顶点事件最晚发生时间
            if (ltv[k] - e->weight < ltv[gettop]) {
                ltv[gettop] = ltv[k] - e->weight;
            }
        } // for end
    } // while end

    // 求ete, lte和关键活动
    for (j = 0; j < GL->numVertexes; j++) {
        for (e = GL->adjList[j].firstedge; e; e->next) {
            k = e->adjvex;
            ete = etv[j];    // 活动最早发生时间
            lte = ltv[k] - e->weight;    // 活动最迟发生时间

            // 两者相等即在关键路径上
            if (ete == lte) {
                printf("<v%d, v%d> length: %d , ", GL->adjList[j].data, GL->adjList[k].data, e->weight);

            }

        }
    }
}

