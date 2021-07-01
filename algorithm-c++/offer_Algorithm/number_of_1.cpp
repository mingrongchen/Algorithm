//
// Created by MingR on 2021/7/1.
//

#include <stdio.h>
#include <stdexcept>

using namespace std;

static int NumberOf1(int n) {
    int count;
    while(n) {
        if (n & 1) {
            count++;
        }
        n = n >> 1;
    } // while

    return count;
}

static int NumberOf2(int n) {
    int count;
    unsigned int flag = 1;
    while(flag) {
        if (n & flag) {
            count++;
        }
        flag = flag << 1;
    } // while

    return count;
}

static int NumberOf1(int n) {
    int count;
    while(n) {
        ++count;
        n = (n - 1) & n;
    } // while

    return count;
}

