//
// Created by CMR on 2019/9/25.
//

#include "4-2-dfs_maze.h"
int n;
int m;
int p;
int q;
int min = 99999999;
int a[51][51];
int book[51][51];
void dfs_maze(int x, int y, int step) {
    // 顺时针， 右、下、左、上
    const int next[4][2] = {{0,1},
                            {1,0},
                            {0,-1},
                            {-1,0}};
    int tx;
    int ty;
    int k;
    // 判断是否到达目标位置
    if (x == p && y == q) {
        // 更新最小值
        if (step < min) {
            min = step;
        }
        return;
    }

    // 枚举四种走法
    for (int i = 0; i <= 3; i++) {
        // 计算下一个点的坐标
        tx = x + next[i][0];
        ty = y + next[i][1];
        // 判断是否越界
        if (tx < 1 || tx > n || ty < 1 || ty > m) {
            continue;
        }

        // 判断该点是否为障碍物或则已经在路径中
        if (a[tx][ty] == 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1; // 标记这个点已经走过
            dfs_maze(tx,ty,step + 1);
            book[tx][ty] = 0;
        }
    }
    return;
}

void dfs_maze_test() {
    const int maze[5][4] = {{0,0,1,0},
                            {0,0,0,0},
                            {0,0,1,0},
                            {0,1,0,0},
                            {0,0,0,1}};
    int startx;
    int starty;
    n = 5;
    m = 4;
    // 初始化迷宫
    for (int i = 1; i <= n; i++){
        for (int j =1; j <= m; j++){
            a[i][j] = maze[i-1][j-1];
        }
    }

    // 初始化起点和终点坐标
    startx = 1;
    starty = 1;
    p = 4;
    q = 3;
    book[startx][starty] = 1;    // 标记起点已在路径中，防止重复走
    // 第一个参数是起点的x坐标，第二个参数是起点的y坐标，第三个参数是初始步数为0
    dfs_maze(startx, starty, 0);

    // 输出最短步数
    printf("%d", min);
    getchar();

    return;
}

