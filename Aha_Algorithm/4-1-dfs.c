//
// Created by CMR on 2019/9/25.
//

#include "4-1-dfs.h"
/*
 * 第四章第一节 深度优先搜索
 * 解决当下该如何做，下一步怎么做跟“当下该如何做”是一样的
 * 采用循环+递归方法来解决问题
 */
int a[10];
int book[10];
int n;

// 解决1~9长度数，全排列问题
void dfs(int step) {    // step 表示在第几个盒子面前
    if (step == n+1) {    // 如果站在第n+1个盒子面前，则表示前n个盒子已经放好扑克牌了
        printf("nfs over.\n");
        // 输出一种排列
        for (int i = 1; i <= n; i++) {
            printf("%d", a[i]);
        }
        printf("\n");

        return;
    }

    // 此时站在第step个盒子面前，应该放那张牌
    // 按照1、2、3。。。n的顺序一一尝试
    for (int i = 1; i <= n; i++) {
        printf("nfs loop begin: %d .\n", i);
        // 判断扑克牌是否还在手上
        if (book[i] == 0) {    // book[i]等于0表示第i号扑克牌还在手上
            printf("book is not used: %d .\n", i);
            // 尝试使用扑克牌i
            a[step] = i;    // 将i号扑克牌放入到第step个盒子中去
            book[i] = 1;    // 标记第i号扑克牌已经不在手上了

            // 第step个盒子紫荆放好扑克牌了，接下来是走到下一个盒子面前
            dfs(step + 1);    // 通过函数递归调用实现
            printf("book is return: %d .\n", i);
            book[i] = 0;    //返回递归时，收回扑克牌
        }
    }
    return;
}
int total=0;
// 解决3位数 + 3位数 = 3位数 问题
void dfs_2(int step){
    if (step == 10) {    // 如果站在第10个盒子面前，则表示前面9个盒子已经放好扑克牌
        // 判断是否满足等式
        if (a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]
        ==a[7]*100+a[8]*10+a[9]){
            // 如果满足要求
            total++;
            printf("%d%d%d + %d%d%d = %d%d%d . \n",
                    a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }
        return;    // 返回之前的一步
    }

    // 此时站在第step个盒子面前，应该放那张牌
    // 按照1、2、3。。。n的顺序一一尝试
    for (int i = 1; i <= 9; i++) {
        // 判断扑克牌i是否还在手上
        if (book[i] == 0) {
            a[step] = i;
            book[i] = 1;

            dfs_2(step + 1);
            book[i] = 0;
        }
    }


}

void dfs_test() {
    // 1~9 数字全排列测试
//    printf("Input: ");
//    scanf("%d", &n); // 输出时n为1~9的整数
//    dfs(1);    // 首先是站在1号小盒子面前

    // 3位数 + 3位数 = 3位数 测试
    dfs_2(1);
    printf("total = %d .\n", total / 2);

    getchar();
    return;
}