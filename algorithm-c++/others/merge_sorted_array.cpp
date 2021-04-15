//
// Created by MingR on 2021/1/12.
//

/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * Note: You may assume that A has enough space (size that is greater or equal to m + n) to hold
 * additional elements from B. The number of elements initialized in A and B are m and n respectively.
 * A和B都已经是排好序的数组，我们只需要从后往前比较就可以了。
 * 因为A有足够的空间容纳A + B，我们使用游标i指向m + n - 1，也就是最大数值存放的地方，从后往前遍历
 * A，B，谁大就放到i这里，同时递减i。
 *
 */



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m + n -1;
        int j = m - 1;
        int k = n - 1;

        while (i >= 0) {
            if (j > 0 && k >= 0) {

                if (A[j] > B[k]) {
                    A[i] = A[j];
                    j--;
                } else {
                    A[i] = B[k];
                    k--;
                }
            } else if (j >= 0){
                A[i] = A[j];
                j--;
            } else if (k >= 0) {
                A[i] = B[k];
                k--;
            }
            i--;
        }
    }
};

static void test() {
    int test_b_length = 5;
    int test_a_length = 10;
    int test_a[] = {1,3,5,7,9,0,0,0,0,0};
    int test_b[] = {1,7,15,27,99};

    Solution().merge(test_a, test_a_length - test_b_length, test_b, test_b_length);

//    for (int i = 0; i < sizeof(arrayTest) / sizeof(arrayTest[0]); i++) {
//        std::cout << "i: " << i << " ,value is :"<< arrayTest[i] <<std::endl;
//    }
    for (int i = 0; i < sizeof(test_a) / sizeof(test_a[0]); i++) {

        std::cout <<" "<< test_a[i] << std::endl;
    }

    std::cout << std::endl << "Test end!" << std::endl;
};

