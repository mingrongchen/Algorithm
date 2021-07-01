//
// Created by MingR on 2021/7/1.
//

#include <stdio.h>
#include <stdexcept>

using namespace std;

/**
 * 几万员工年龄排序，时间效率为O(n)，辅助内存不超过O(n)
 * @param data
 * @param length
 */
static void SortAge(int data[], int length) {
    if (!data || length < 0) {
        return;
    }

    const int oldestAge = 99;
    int timesOfAge[oldestAge + 1];

    // 年龄出现的次数加一，索引值为具体年龄
    for (int i = 0; i <= oldestAge; ++i) {
        timesOfAge[i] = 0;
    }

    // 遍历data数据
    for (int i = 0; i < length; ++i) {
        int age = age[i];
        if (age < 0 || age > oldestAge) {
            throw logic_error("age out of range.");
        }
        ++timesOfAge[age];    // 对应年龄出现的次数加一
    }

    int index = 0;
    for (int i = 0; i <= oldestAge; ++i) {
        //每个年龄出现的次数
        for (int j = 0; j < timesOfAge[i]; ++j) {
            data[index] = i;
            ++index;
        }
    }
}