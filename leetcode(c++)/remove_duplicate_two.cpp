//
// Created by MingR on 2021/1/12.
//

/*
 * Follow up for "Remove Duplicates": What if duplicates are allowed at most twice?
 * For example, Given sorted array A = [1,1,1,2,2,3],
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */

#include <iostream>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }

        int j = 0;
        int num = 0;
        for (int i = 1; i < n; i++) {
            if (A[j] == A[i]) {
                num++;
                if (num < 2) {
                    A[++j] = A[i];
                }
            } else {
                A[++j] = A[i];
                num = 0;
            }
        }

        return j + 1;
    }
};

static void test() {
    int arrayTest[8] = {1,1,1,2,3,4,4,4};
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
