//
// Created by MingR on 2021/1/12.
//

/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5, Return
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 * 第k层有k个元素
 * 每层第一个以及最后一个元素值为1
 * 对于第k（k > 2）层第n（n > 1 && n < k）个元素A[k][n]，A[k][n] = A[k-1][n-1] + A[k-1][n]
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vals;
        vals.resize(numRows);

        for (int i = 0; i < numRows; i++) {
            vals[i].resize(i + 1);

            vals[i][0] = 1;
            vals[i][vals[i].size() - 1] = 1;

            for (int j = 1; j < vals[i].size() - 1; j++) {
                vals[i][j] = vals[i - 1][j -1] + vals[i - 1][j];
            }

        }

        return vals;
    }
};

static void test() {
    vector<vector<int>> arrayTest = Solution().generate(5);

//    for (int i = 0; i < sizeof(arrayTest) / sizeof(arrayTest[0]); i++) {
//        std::cout << "i: " << i << " ,value is :"<< arrayTest[i] <<std::endl;
//    }
    for (int i = 0; i < arrayTest.size(); i++) {

        for (int k = 0; k < arrayTest.size() - i - 1; k++) {
            std::cout <<" ";
        }

        for (int j = 0; j < arrayTest[i].size(); j++) {
            std::cout <<" "<< arrayTest[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Test end!" << std::endl;
};
