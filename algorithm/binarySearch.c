//
// Created by MingR on 2021/6/29.
//

#include <stdio.h>


/**
 * 基于有序表的二分查找算法
 * 时间复杂度：logn
 * @param a
 * @param n
 * @param key
 * @return
 */
static int Binary_Search(int *a, int n, int key) {
    int low, high ,mid;

    low = 1;
    high = n;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (key < a[mid]) {
            high = mid - 1;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return 0;
}