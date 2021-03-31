//
// Created by CMR on 2019/9/8.
//
/*
 * 啊哈算法 第二章 第一节
 * 解密QQ号 队列
 * 原数据：6 3 1 7 5 8 9 2 4
 * 解密数据: 6 1 5 9 4 7 2 8 3
 */

#include "2-1-queue.h"

void queue_test(){
    // 原数据为6 3 1 7 5 8 9 2 4，自定义从1开始
    int queue[102] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4};
    int head;
    int tail;

    // 初始化队列
    head = 1;
    tail = 10;

    while (head < tail) {
        // 打印队列头，并出列
        printf("%d ", queue[head]);
        head++;

        // 先将新队首的数添加到队尾
        queue[tail] = queue[head];
        tail++;
        // 再将队首出列
        head++;
    }

    printf("\n2-1-queue test is all done.");
}

void queue_test2() {
    // 9位qq号数据，首位加0，共10位
    int data[10] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4};
    Queue queue;
    queue.head = 1;
    queue.tail = 1;

    // 结构体进队列
    for (int i = 1; i < (sizeof(data) / sizeof(int)); i++){
        queue.data[i] = data[i];
        queue.tail++;
    }

    // 打印结构体数据
    for (int i =1 ; i < queue.tail; i++) {
        printf("%d ", queue.data[i]);
    }

    printf("\n");
    // 打印队列解密qq号
    while (queue.head < queue.tail) {
        printf("%d ", queue.data[queue.head]);
        // 队首出列，并打印
        queue.head++;

        queue.data[queue.tail] = queue.data[queue.head];
        // 队尾入列
        queue.tail++;
        // 队首出列
        queue.head++;
    }


    printf("\n2-1-queue test 2 all done.");


}
