//
// Created by MingR on 2021/1/12.
//

/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 */


#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j = 0;
        for (i = 0; i < n; i++) {
            if (A[i] == elem) {
                continue;
            }

            A[j] = A[i];
            j++;
        }

        return j;
    }
};

static void test() {
    int arrayTest[6] = {1,2,2,3,2,4};
    for (int i = 0; i < sizeof(arrayTest) / sizeof(arrayTest[0]); i++) {
        std::cout << "i: " << i << " ,value is :"<< arrayTest[i] <<std::endl;
    }
    std::cout << "After!" << std::endl;
    int result = Solution().removeElement(arrayTest, sizeof(arrayTest) / sizeof(arrayTest[0]), 2);

//    for (int i = 0; i < sizeof(arrayTest) / sizeof(arrayTest[0]); i++) {
//        std::cout << "i: " << i << " ,value is :"<< arrayTest[i] <<std::endl;
//    }
    std::cout << "result: " << result <<std::endl;
    for (int i = 0; i < result; i++) {
        std::cout << "i: " << i << " ,value is :"<< arrayTest[i] <<std::endl;
    }

    std::cout << "Test end!" << std::endl;
};

