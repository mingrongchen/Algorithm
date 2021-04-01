//
// Created by MingR on 2021/3/31.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAXSIZE 10

/*
 * 有一个含有n个整数的无序数据序列，所有的数据元素均不相同，采用整数数组R[0，n-1]存储，请完成以下任务：
 * (1)设计一个尽可能高效的算法，输出该序列中第k(1≤k≤n)小的元素，算法中给出适当的注释信息。
 * (2）分析你所设计的求解算法的平均时间复杂度，并给出求解过程
 */

static void rand_array (int *p) {
    srand(time(0));    // 初始化随机数种子

    for (int i = 0; i < MAXSIZE; i++){
        p[i] = rand() % 100 + 1;    // 随机生成100以内的数字
    }
}

static void print_array (int *p) {
    for (int i = 0; i < MAXSIZE; i++){
        printf("print_array index %d, data is %d ...\n", i, p[i]);
    }
}

static void find_k_test() {
    printf("find_k_test start ...\n");

    int array[MAXSIZE];
    rand_array(array);
    print_array(array);


    printf("find_k_test end ...\n");
}
