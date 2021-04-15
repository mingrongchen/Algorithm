//
// Created by MingR on 2021/1/12.
//

/*
 * Given a sorted array, remove the duplicates in place such that > each element appear only once
 * and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example, Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 */

#include <iostream>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (A[j] != A[i]) {
                A[++j] = A[i];
            }
        }

        return j + 1;
    }
};

static void test() {
    int arrayTest[6] = {1,1,2,3,4,4};
    for (int i = 0; i < sizeof(arrayTest) / sizeof(arrayTest[0]); i++) {
        std::cout << "i: " << i << " ,value is :"<< arrayTest[i] <<std::endl;
    }
    std::cout << "After!" << std::endl;
    int result = Solution().removeDuplicates(arrayTest, sizeof(arrayTest) / sizeof(arrayTest[0]));

//    for (int i = 0; i < sizeof(arrayTest) / sizeof(arrayTest[0]); i++) {
//        std::cout << "i: " << i << " ,value is :"<< arrayTest[i] <<std::endl;
//    }
    std::cout << "result: " << result <<std::endl;
    for (int i = 0; i < result; i++) {
        std::cout << "i: " << i << " ,value is :"<< arrayTest[i] <<std::endl;
    }

    std::cout << "Test end!" << std::endl;
};

