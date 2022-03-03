//
// Created by CMR on 2019/9/26.
//
/*
 * 第四章第五节 小岛探险
 * 深度搜索 的应用
 * 着色法
 */
#include "4-5-Island_Adventure.h"

const int IslandMap[10][10] = {{1,2,1,0,0,0,0,0,2,3},
                               {3,0,2,0,1,2,1,0,1,2},
                               {4,0,1,0,1,2,3,2,0,1},
                               {3,2,0,0,0,1,2,4,0,0},
                               {0,0,0,0,0,0,1,5,3,0},
                               {0,1,2,1,0,1,5,4,3,0},
                               {0,1,2,3,1,3,6,2,1,0},
                               {0,0,3,4,8,9,7,5,0,0},
                               {0,0,0,3,7,8,6,0,1,2},
                               {0,0,0,0,0,0,0,0,1,0}};


void island_test() {
    // 顺时针， 右、下、左、上
    const int next[4][2] = {{0,1},
                            {1,0},
                            {0,-1},
                            {-1,0}};
    Note queue[2501];
    int head = 1;
    int tail = 1;
    int a[51][51];
    int book[51][51] = {0};
    int sum;
    int max = 0;
    int mx;
    int my;
    int n = 10;
    int m = 10;
    int startx = 6;
    int starty = 8;
    int tx;
    int ty;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = IslandMap[i-1][j-1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // 初始化
    queue[tail].x = startx;
    queue[tail].y = starty;
    tail++;
    book[startx][starty] = 1;
    sum = 1;

    // 当队列不为空的时候循环
    while (head < tail) {
        // 枚举四个方向
        for (int i = 0; i <= 3; i++) {
            tx = queue[head].x + next[i][0];
            ty = queue[head].y + next[i][1];

            // 判断是否越界
            if (tx < 1 || tx > n || ty < 1 || ty > m) {
                continue;
            }

            // 判断是否是陆地或者曾经走过
            if (a[tx][ty] > 0 && book[tx][ty] == 0) {
                sum++;
                // 每个点只入队依次
                book[tx][ty] = 1;
                queue[tail].x = tx;
                queue[tail].y = ty;
                tail++;
            }
        }
        head++;    // 注意，当一个拓展点结束后，出列继续往下拓展
    }

    // 最后输出岛屿的大小
    printf("The island is : %d .\n", sum);

    getchar();
    return;
}

int a[51][51];
int book[51][51];
int n;
int m;
int sum;

void dfs_island(int x, int y, int color) {
    // 顺时针， 右、下、左、上
    const int next[4][2] = {{0,1},
                            {1,0},
                            {0,-1},
                            {-1,0}};
    int tx;
    int ty;
    // 对当前格子着色
    a[x][y] = color;
    // 枚举下一步的坐标
    for (int i = 0; i <= 3; i++) {
        tx = x + next[i][0];
        ty = y + next[i][1];

        // 判断是否越界
        if (tx < 1 || tx > n || ty < 1 || ty > m) {
            continue;
        }

        // 判断是否是陆地
        if (a[tx][ty] > 0 && book[tx][ty] == 0) {
            sum++;
            book[tx][ty] = 1;    // 标记这个点
            dfs_island(tx, ty, color);
        }
    }
    return;
}

void dfs_island_test() {
    int startx = 6;
    int starty = 8;

    n = 10;
    m = 10;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = IslandMap[i-1][j-1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    book[startx][starty] = 1;
    sum = 1;
    // 从降落的位置开始，即标记点的位置开始
    dfs_island(startx, starty, -1);

    // 最后输出岛屿的大小
    printf("The island is : %d .\n", sum);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    getchar();
    return;
}

/*
 * 求图中独立子图的个数
 * Floodfill漫水填充法（也称为种子填充法）
 */
void dfs_island_test2() {
    int num = 0;

    n = 10;
    m = 10;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = IslandMap[i-1][j-1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // 遍历整个图，对每个大于0的点尝试进行dfs染色
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] > 0) {
                num--;    // 小岛需要染色的编号，每个小岛染不同的颜色
                book[i][j] = 1;
                dfs_island(i, j, num);
            }
        }
    }

    // 最后输出岛屿的大小
    printf("The island is : %d .\n", sum);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    getchar();
    return;
}