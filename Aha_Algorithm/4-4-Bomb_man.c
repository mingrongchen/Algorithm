//
// Created by CMR on 2019/9/26.
//
/*
 * 第四章第四节
 * 使用广度优先算法和深度优先算法解决炸弹人问题
 *
 */

#include "4-4-Bomb_man.h"

char a[20][21];    // 存储地图
const char bomb_maze[13][13] = {{'#','#','#','#','#','#','#','#','#','#','#','#','#'},
                                {'#','G','G','.','G','G','G','#','G','G','G','.','#'},
                                {'#','#','#','.','#','G','#','G','#','G','#','G','#'},
                                {'#','.','.','.','.','.','.','.','#','.','.','G','#'},
                                {'#','G','#','.','#','#','#','.','#','G','#','G','#'},
                                {'#','G','G','.','G','G','G','.','#','.','G','G','#'},
                                {'#','G','#','.','#','G','#','.','#','.','#','.','#'},
                                {'#','#','G','.','.','.','G','.','.','.','.','.','#'},
                                {'#','G','#','.','#','G','#','#','#','.','#','G','#'},
                                {'#','.','.','.','G','#','G','G','G','.','G','G','#'},
                                {'#','G','#','.','#','G','#','G','#','.','#','G','#'},
                                {'#','G','G','.','G','G','G','#','G','.','G','G','#'},
                                {'#','#','#','#','#','#','#','#','#','#','#','#','#'}};

int getNum(int i, int j) {
    int sum = 0;
    int x;
    int y;

    // 向上统计可以消灭的敌人数
    x = i;
    y = j;
    while (a[x][y] != '#') {    // 如果不是墙就继续
        // 如果当前是敌人就计数
        if (a[x][y] == 'G') {
            sum++;
        }
        x--;
    }

    // 向下统计可以消灭的敌人数
    x = i;
    y = j;
    while (a[x][y] != '#') {    // 如果不是墙就继续
        // 如果当前是敌人就计数
        if (a[x][y] == 'G') {
            sum++;
        }
        x++;
    }

    // 向左统计可以消灭的敌人数
    x = i;
    y = j;
    while (a[x][y] != '#') {    // 如果不是墙就继续
        // 如果当前是敌人就计数
        if (a[x][y] == 'G') {
            sum++;
        }
        y--;
    }

    // 向右统计可以消灭的敌人数
    x = i;
    y = j;
    while (a[x][y] != '#') {    // 如果不是墙就继续
        // 如果当前是敌人就计数
        if (a[x][y] == 'G') {
            sum++;
        }
        y++;
    }

    return sum;
}

void bfs_bomb_test() {
    // 顺时针， 右、下、左、上
    const int next[4][2] = {{0,1},
                            {1,0},
                            {0,-1},
                            {-1,0}};
    Note queue[401];
    int head = 1;
    int tail = 1;
    int book[20][20] = {0};
    int sum;
    int max = 0;
    int mx;
    int my;
    int n = 13;
    int m = 13;
    int startx = 3;
    int starty = 3;
    int tx;
    int ty;

    for (int i = 0; i <= n -1; i++) {
        for (int j = 0; j <= m -1; j++) {
            a[i][j] = bomb_maze[i][j];
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

    queue[tail].x = startx;
    queue[tail].y = starty;
    tail++;
    book[startx][starty] = 1;
    max = getNum(startx, starty);
    mx = startx;
    my = starty;
    // 当队列不为空的时候循环
    while (head < tail) {
        // 枚举四个方向
        for (int i = 0; i <= 3; i++) {
            // 尝试u的下一个点的坐标
            tx = queue[head].x + next[i][0];
            ty = queue[head].y + next[i][1];

            // 判断是否越界
            if (tx < 0 || tx > n-1 || ty < 1 || ty > m -1) {
                continue;
            }

            // 判断是否为平地或者曾经走过
            if (a[tx][ty] == '.' && book[tx][ty] == 0) {
                // 每个点只入队依次，所以只需要标记这个点已经走过
                book[tx][ty] = 1;
                // 插入新拓展的点到队列中去
                queue[tail].x = tx;
                queue[tail].y = ty;
                tail++;

                // 统计当前新拓展的点可以消灭敌人的总数
                sum = getNum(tx, ty);
                // 跟新max的值
                if (sum > max) {
                    // 如果当前统计出所能消灭敌人数大于max，更新max，并用mx和my记录该点的坐标
                    max = sum;
                    mx = tx;
                    my = ty;
                }
            }
        }
        head++; // 注意，当一个点拓展结束后，必须要head++才能对后面的点进行拓展
    }

    // 最后输入这个点和最多可以消灭的敌人的总数
    printf("Put bomb in (%d, %d), there can kill %d enemies.", mx, my, max);

    getchar();
    return;
}

int book[20][20];
int max;
int mx;
int my;
int n;
int m;
void dfs_bomb(int x, int y) {
    // 顺时针， 右、下、左、上
    const int next[4][2] = {{0,1},
                            {1,0},
                            {0,-1},
                            {-1,0}};
    int sum;
    int tx;
    int ty;
    // 计算当前点可以消灭的敌人总数
    sum = getNum(x, y);

    // 更新max的值
    if (sum > max) {
        max = sum;
        mx = x;
        my = y;
    }

    // 枚举四个方向
    for (int i = 0; i <= 3; i++) {
        // 下一个节点的坐标
        tx = x + next[i][0];
        ty = y + next[i][1];

        // 判断是否越界
        if (tx < 1 || tx > n-1 || ty < 1 || ty > m-1 ) {
            continue;
        }

        // 判断是否围墙或者已经走过
        if (a[tx][ty] == '.' && book[tx][ty] == 0){
            book[tx][ty] = 1;    // 标记该点已经走过
            dfs_bomb(tx, ty);    // 开始尝试下一个点
        }
    }
    return;
}

void dfs_bomb_test() {
    int startx = 3;
    int starty = 3;
    n = 13;
    m = 13;

    for (int i = 0; i <= n -1; i++) {
        for (int j = 0; j <= m -1; j++) {
            a[i][j] = bomb_maze[i][j];
            printf("%c", a[i][j]);
        }
        printf("\n");
    }

    // 从小人所在位置开始尝试
    book[startx][starty] = 1;
    max = getNum(startx, starty);
    mx = startx;
    my = starty;
    dfs_bomb(startx, starty);

    // 最后输入这个点和最多可以消灭的敌人的总数
    printf("Put bomb in (%d, %d), there can kill %d enemies.", mx, my, max);

    getchar();
    return;

}
