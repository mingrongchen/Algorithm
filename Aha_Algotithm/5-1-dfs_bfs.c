//
// Created by CMR on 2019/9/26.
//
/*
 * 第五章第一节
 * 介绍深度优先和广度优先在图中的应用
 * 图表示为邻接举证
 */
#include "5-1-dfs_bfs.h"

const int data[5][2] = {{1,2},
                        {1,3},
                        {1,5},
                        {2,4},
                        {3,5}};
int book[101];
int sum;
int n;
int m;
int e[101][101];
void dfs_5(int cur) {
    printf("%d.\n", cur);    // 访问当前节点
    sum++;    // 没访问一次，记一次数
    if (sum == n) {    // 所有顶点访问完毕后，返回
        return;
    }

    for (int i = 1; i <= n; i++) {    // 从1~n号顶点遍历一遍，查看哪些顶点与cur顶点相连
        // 判断当前顶点是否有边，标记该顶点是否被访问过
        if (e[cur][i] == 1 && book[i] == 0) {
            book[i] = 1;    // 标记该顶点访问过
            dfs_5(i);    // 再从顶点i继续遍历
        }
    }
    return;
}

void dfs_5_test() {
    n = 5;
    m = 5;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = 99999999;
            }
        }
    }

    int a;
    int b;
    // 输入边
    for (int i = 1; i <= m; i++) {
        a = data[i][0];
        b = data[i][1];
        e[a][b] = 1;
        e[b][a] = 1;    // 无向图
    }

    // 从顶点1出发
    book[1] = 1;
    dfs_5(1);

    getchar();
    return;
}