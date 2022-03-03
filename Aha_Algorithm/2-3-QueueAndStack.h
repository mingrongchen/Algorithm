//
// Created by CMR on 2019/9/25.
//

#ifndef AHA_ALGORITHM_2_3_QUEUEANDSTACK_H
#define AHA_ALGORITHM_2_3_QUEUEANDSTACK_H

#include <stdio.h>
#include <string.h>

typedef struct {
    int data[100];
    int head;
    int tail;
} Queue;

typedef  struct {
    int data[10];
    int top;
} Stack;

void queque_and_stack_test();


#endif //AHA_ALGORITHM_2_3_QUEUEANDSTACK_H
