//
// Created by CMR on 2019/9/25.
//
/*
 * 啊哈算法 第二章第三节
 * A： 2 4 1 2 5 6
 * B：3 1 3 5 6 4
 */
#include "2-3-QueueAndStack.h"

const int DATA_A[6] = {2, 4, 1, 2, 5, 6};
const int DATA_B[6] = {3, 1, 3, 5, 6, 4};

void queque_and_stack_test(){
    printf("Function: %s , Line: %d .\n", __FUNCTION__, __LINE__);
    Queue q1;
    Queue q2;
    Stack s;
    int book[10];
    int t;

    // 初始化队列
    q1.head = 1;
    q1.tail = 1;
    q2.head = 1;
    q2.tail =1;
    // 初始化栈
    s.top = 0;
    // 初始化用来标记的数组，用来标记哪些牌已经在桌上
    for (int i = 0; i < 10; i++) {
        book[i] = 0;
    }

    // 依次向队列中插入6个数
    for (int i = 1; i <= 6; i++) {
        q1.data[q1.tail] = DATA_A[i-1];
        q1.tail++;
    }
    for (int i = 1; i <= 6; i++) {
        q2.data[q2.tail] = DATA_B[i-1];
        q2.tail++;
    }

    // 当队列不为空时执行循环
    while (q1.head < q1.tail && q2.head < q2.tail){
        t = q1.data[q1.head];    // A先出第一张牌
        // 判断A当前打出的牌是否能赢牌
        if (book[t] == 0) {    // 表明桌面上没有牌面为t的牌
            // 因此A没有赢牌
            q1.head++;    // A已经打出一张牌，因此队列出列
            s.data[++s.top] = t;    // 再次把打出的牌放到桌面上，即入栈
            book[t] = 1;    // 标记桌面上现在已经有牌面为t的牌
        } else {
            // A此轮可以赢牌
            q1.head++;    // 同样A已经打出一张牌，因此队列出列
            q1.data[q1.tail] = t;    //紧接着把打出的牌放到手中牌的末尾
            q1.tail++;
            while (s.data[s.top] != t){    // 把桌上可以赢得的牌依次放到手中牌的末尾
                book[s.data[s.top]] = 0;    // 取消标记
                q1.data[q1.tail] = s.data[s.top];    // 依次放入队尾
                q1.tail++;
                s.top--;    // 栈中少了一张牌栈顶减一
            }
        }

        t = q2.data[q2.head];    // B出一张牌
        // 判断B当前打出的牌是否能赢牌
        if (book[t] == 0) {
            // B未赢牌
            q2.head++;
            s.data[++s.top] = t;
            book[t] = 1;
        } else {
            // B 可赢牌
            q2.head++;
            q2.data[q2.tail] = t;
            q2.tail++;
            while (s.data[s.top] != t){
                book[s.data[s.top]] = 0;
                q2.data[q2.tail] = s.data[s.top];
                q2.tail++;
                s.top--;
            }
        }
    }

    if (q2.head == q2.tail) {
        printf("A WIN.\n");
        printf("A card is :");
        for (int i = q1.head; i < q1.tail - 1; i++) {
            printf("  %d", q1.data[i]);
        }
        if (s.top > 0) {
            printf("\n table card is: ");
            for (int i = 1; i <= s.top; i++){
                printf("  %d", s.data[i]);
            }
        } else {
            printf("\n table has no card");
        }
    } else {
        printf("B WIN.\n");
        printf("B card is:");
        for (int i = q2.head; i < q2.tail - 1; i++) {
            printf("  %d", q2.data[i]);
        }
        if (s.top > 0) {
            printf("\n table card is: ");
            for (int i = 1; i <= s.top; i++){
                printf("  %d", s.data[i]);
            }
        } else {
            printf("\n table has no card");
        }
    }

    getchar();
    printf("Function All Done. \n");
}
