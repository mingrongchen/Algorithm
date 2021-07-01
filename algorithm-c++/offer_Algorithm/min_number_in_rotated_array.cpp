//
// Created by MingR on 2021/7/1.
//

#include <stdio.h>
#include <stdexcept>

using namespace std;



static int MinInOrder(int* numbers, int index1, int index2) {
    int result = numbers[index1];
    for (int i = index1 + 1; i < index2; ++i) {
        if (result > numbers[i]) {
            result = numbers[i];
        } // if
    } //for

    return result;
}


/**
 * 示例：{0,1,1,1,1}，{1,0,1,1,1}
 * @param numbers
 * @param length
 * @return
 */
static int Min(int* numbers, int length) {
    if (!numbers || length <= 0) {
        throw logic_error("Invalid parameters.");
    }

    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;

    while (numbers[index1] >= numbers[index2]) {
        if ((index2 - index1) == 1) {
            indexMid = index2;
            break;
        }

        indexMid = (index1 + index2) / 2;

        // 当index1、index2、indexMid三个数字相等时，只能顺序查找
        if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1]) {
            return MinInOrder(numbers, index1, index2);
        }

        if (numbers[indexMid] >= numbers[index1]) {
            index1 = indexMid;
        } else if (numbers[indexMid] <= numbers[index2]) {
            index2 = indexMid;
        } // if
    } // while

    return numbers[indexMid];

}