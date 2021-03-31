//
// Created by CMR on 2019/9/26.
//
/*
 * 第四章第六节 水管工游戏
 *
 */


#include "4-6-water_pip.h"

const int pip_map[5][4] = {{5,3,5,3},
                           {1,5,3,0},
                           {2,3,5,1},
                           {6,1,1,5},
                           {1,5,5,4}};
int a[51][51];
int book[51][51];
int n;
int m;
int flag = 0;
// add
Note s[100];
int top = 0;
// x、y表示当前处理格子的坐标，front表示进水口方向
// 进水方向表示  左边：1，上边：2，右边：3，下边：4
void dfs_pipe(int x, int y, int front) {
    if (x == n && y == m+1) {
        flag = 1;    // 赵东铺设方案
        for (int i = 0; i <= top; i++){
            printf("(%d, %d)",s[i].x,s[i].y);
        }
        printf("\n");
        return;
    }

    // 判断是否越界
    if (x < 1 || x > n || y < 1 || y > m) {
        return;
    }

    // 如果该管道在路径中已经使用过
    if (book[x][y] == 1) {
        return;
    }
    book[x][y] = 1;    // 标记使用当前这个管道

    // 将当前尝试坐标入栈
    top++;
    s[top].x = x;
    s[top].y = y;

    // 当前水管是直管的情况
    if (a[x][y] >= 5 && a[x][y] <= 6){
        if (front == 1) {    // 进水管在左边的情况
            dfs_pipe(x, y + 1, 1);    // 只能使用5号这种摆放方式
        }

        if (front == 2) {    // 进水口在上边的情况
            dfs_pipe(x+1, y, 2);    // 只能用6号这种摆放方式
        }

        if (front == 3) {   // 右
            dfs_pipe(x, y-1, 3);    // 5号
        }

        if (front == 4) {    // 下
            dfs_pipe(x-1, y, 4);    // 6号
        }
    }

    // 当水管是弯管的情况
    if (a[x][y] >= 1 && a[x][y] <= 4) {
        if (front == 1){
            dfs_pipe(x+1, y, 2);    // 3号
            dfs_pipe(x-1, y, 4);    // 4号
        }

        if (front == 2){
            dfs_pipe(x, y+1, 1);    // 1号
            dfs_pipe(x, y-1, 3);    // 4号
        }

        if (front == 3){
            dfs_pipe(x-1, y, 4);    // 1号
            dfs_pipe(x+1, y, 2);    // 2号
        }

        if (front == 4){
            dfs_pipe(x, y+1, 1);    // 2号
            dfs_pipe(x, y-1, 3);    // 3号
        }
    }

    book[x][y] = 0;    // 取消标记
    top--;    // 将当前尝试的坐标出栈
    return;
}


void water_pip_test() {
    n = 5;
    m = 4;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = pip_map[i-1][j-1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    // 开始搜索， 从1,1点开始，进水方向也是1
    dfs_pipe(1, 1, 1);
    if (flag == 0) {
        printf("Impossible. \n");
    } else {
        printf("Possible. \n");
    }

    getchar();
    return;
}
