//
// Created by MingR on 2022/3/3.
//

#include <stdio.h>


#define PRT(format,...)  printf("[File:%s, Line:%d] "format, __FILE__, __LINE__, ##__VA_ARGS__)

void practice2() {
    enum color {green, yellow, red=0, black};

    PRT("green = , %d ", green);
    PRT("yellow = , %d ", yellow);
    PRT("red = , %d ", red);
    PRT("black = , %d ", black);

}
