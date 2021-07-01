//
// Created by MingR on 2021/7/1.
//

#include <stdio.h>
#include <stdexcept>

using namespace std;

static void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 将比选择小的数字移到数组左边，比选择大的数字移动到右边
 * @param data
 * @param length
 * @param start
 * @param end
 * @return
 */
static int Partition(int data[], int length, int start, int end) {
    if (!data || length <= 0 || start < 0 || end >= length) {
        throw logic_error("Invalid Parameters.");
    }

    int index = start;    // random(start , end)
    Swap(&data[index], &data[end]);

    int small = start -1;

    for (index = start; index < end; ++index) {
        if (data[index] < data[end]) {
            ++small;
            if (small != index) {
                Swap(&data[index], &data[small]);
            } // if
        } // if
    } // for

    ++small;
    Swap(&data[small], &data[end]);

    return small;

}


static void QuickSort(int data[], int length, int start, int end) {

    if (start == end) {
        return;
    }

    int index = Partition(data, length, start, end);

    if (index > start) {
        QuickSort(data, length, start, index - 1);
    }

    if (index < end) {
        QuickSort(data, length, index + 1, end);
    }
}