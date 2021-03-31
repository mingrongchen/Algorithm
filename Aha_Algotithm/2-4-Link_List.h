//
// Created by CMR on 2019/9/25.
//

#ifndef AHA_ALGORITHM_2_4_LINK_LIST_H
#define AHA_ALGORITHM_2_4_LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node, *PNode;

void link_test();

#endif //AHA_ALGORITHM_2_4_LINK_LIST_H
