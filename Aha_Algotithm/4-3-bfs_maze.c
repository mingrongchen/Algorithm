//
// Created by CMR on 2019/9/25.
//
/*
 * 第四章第三节 广度优先搜索
 *
 */
#include "4-3-bfs_maze.h"

void bfs_maze_test() {
    const int maze[5][4] = {{0,0,1,0},
                            {0,0,0,0},
                            {0,0,1,0},
                            {0,1,0,0},
                            {0,0,0,1}};
// 顺时针， 右、下、左、上
    const int next[4][2] = {{0,1},
                            {1,0},
                            {0,-1},
                            {-1,0}};
    Note queue[2501];
    int a[51][51] = {0};
    int book[51][51] = {0};
    int head = 1;
    int tail = 1;
    int n = 5;
    int m = 4;
    // 初始化迷宫
    for (int i = 1; i <= n; i++){
        for (int j =1; j <= m; j++){
            a[i][j] = maze[i-1][j-1];
        }
    }

    int startx = 1;
    int starty = 1;
    int p = 4;
    int q = 3;
    int tx;
    int ty;
    int flag;

    queue[tail].x = startx;
    queue[tail].y = starty;
    queue[tail].f = 0;
    queue[tail].s = 0;
    tail++;
    book[startx][starty] = 1;

    flag = 0;    // 用来标记是否到达目标点
    while (head < tail) {
        // 枚举四个方向
        for (int i = 0; i <= 3; i++) {
            // 计算下一个点的坐标
            tx = queue[head].x + next[i][0];
            ty = queue[head].y + next[i][1];

            // 判断是否越界
            if (tx < 1 || tx > n || ty < 1|| ty > m) {
                continue;
            }

            // 判断是否是障碍物 或者 已经在路径中
            if (a[tx][ty] == 0 && book[tx][ty] == 0) {
                // 标记该点位已经走过
                // 宽度优先搜索不需要递归，对走过标记好的点不需要还原
                book[tx][ty] = 1;
                // 插入新的点到队列中
                queue[tail].x = tx;
                queue[tail].y = ty;
                queue[tail].f = head;
                queue[tail].s = queue[head].s + 1;    // 步数是父亲步数 +1
                tail++;
            }

            // 如果到了目标点，停止拓展，任务结束，退出循环
            if (tx == p && ty == q) {
                //
                flag = 1;
                break;
            }

        }

        if (flag == 1) {
            break;
        }
        head++; // 注意，当一个点拓展结束后，head++才能对后面的点再进行拓展
    }

    // 打印队列中末尾最后一个点的步数
    // 注意tail是指向队列队尾的下一个位置，所以需要-1
    printf("%d", queue[tail - 1].s);


    getchar();
    return;
}
