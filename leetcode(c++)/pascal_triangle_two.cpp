//
// Created by MingR on 2021/1/12.
//

/*
 * Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3, Return [1,3,3,1].
 * 这里我们仅仅需要得到的第k层的集合，但只能使用O(k)的空间。所以不能用前面二维数组
 * 的方式，只能使用一位数组滚动计算。
 * 从后往前计算。
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vals;
        vals.resize(rowIndex + 1, 1);

        for (int i = 0; i < rowIndex + 1; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                vals[j] = vals[j] + vals[j - 1];
            }

        }
        return vals;
    }
};

static void test() {
    vector<int> arrayTest = Solution().getRow(3);

//    for (int i = 0; i < sizeof(arrayTest) / sizeof(arrayTest[0]); i++) {
//        std::cout << "i: " << i << " ,value is :"<< arrayTest[i] <<std::endl;
//    }
    for (int i = 0; i < arrayTest.size(); i++) {
        std::cout <<" "<< arrayTest[i];
    }

    std::cout << std::endl << "Test end!" << std::endl;
};