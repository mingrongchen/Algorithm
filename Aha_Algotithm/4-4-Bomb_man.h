//
// Created by CMR on 2019/9/26.
//

#ifndef AHA_ALGORITHM_4_4_BOMB_MAN_H
#define AHA_ALGORITHM_4_4_BOMB_MAN_H

#include <stdio.h>
#include <string.h>

typedef struct note {
    int x;
    int y;
}Note;

int getNum(int, int);
void bfs_bomb_test();
void dfs_bomb(int, int);
void dfs_bomb_test();


#endif //AHA_ALGORITHM_4_4_BOMB_MAN_H
