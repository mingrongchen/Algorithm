//
// Created by CMR on 2019/9/8.
//
/*
 * 啊哈算法第二章 第二节
 * 解密回文 栈
 * 问题：
 * 文中栈存在问题，栈0不放数据？
 * 中点位置寻找存在歧义？
 */
#include "2-2-stack.h"

void stack_test() {
    char a[101];
    char s[101];
    int len;
    int mid;
    int next;
    int top;

    gets(a);
    len = strlen(a);
    mid = len / 2 - 1;
    printf("a data length: %d, mid: %d\n", len, mid);

    // 栈初始化, 栈0处不放数据
    top = 0;
    // 将mid前的字符依次入栈
    for (int i = 0; i <= mid; i++) {
        s[++top] = a[i];
    }

    // 判断字符串的长度是奇数还是偶数，并找出需要进行字符匹配的起始下标
    if (len % 2 == 0) {
        next = mid + 1;
    } else {
        next = mid + 2;
    }
    printf("a data length: %d, mid: %d, next: %d .\n", len, mid, next);

    // 开始匹配
    for (int i = next; i <= len; i++) {
        if (a[i] != s[top]){
            break;
        }
        top--;
    }

    // 如果top的值为0，则说明栈内所有字符都被一一匹配了
    if (top == 0) {
        printf("Yes.\n");
    } else {
        printf("No.\n");
    }

    getchar();
}

