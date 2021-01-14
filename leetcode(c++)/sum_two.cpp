//
// Created by MingR on 2021/1/14.
//

/*
 *Given an array of intergers, find two numbers such that they add up to a specific target number. The
 * function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2 Please note that your returned answers (both index1 and
 * index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9 Output: index1=1, index2=2
 * 题目翻译： 这道题目的意思是给定一个数组和一个值，让求出这个数组中两个值的和等于这个给定值的坐
 * 标。输出是有要求的，1， 坐标较小的放在前面，较大的放在后面。2， 这俩坐标不能为零。
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // 边角问题处理
        vector<int> ret;

        if (numbers.size() <= 1) {
            return ret;
        }

        // 新建一个map<key, value>来存储numbers里的元素和index
        unordered_map<int, int> myMap;
        for (int i = 0; i < numbers.size(); ++i) {
            myMap[numbers[i]] = i;
        }

        for (int i = 0; i < numbers.size(); ++i) {
            int rest_val = target - numbers[i];

            if (myMap.find(rest_val) != myMap.end()) {
                int index = myMap[rest_val];

                // 同一个数字，pass
                if (index == i) {
                    continue;
                }

                if (index < i) {
                    ret.push_back(index + 1);
                    ret.push_back(i + 1);
                    return ret;
                } else {
                    ret.push_back(i + 1);
                    ret.push_back(index + 1);
                    return ret;
                }
            }
        }
    }
};

static void test() {
    int test_b[] = {1,7,15,27,99};
    vector<int> arrayTest(test_b, test_b + sizeof(arrayTest) / sizeof(arrayTest[0]));

    vector<int> result = Solution().twoSum(arrayTest, 22);

    if (result.size() > 0) {
        std::cout <<"Output: "<< result[0] << " , " <<result[1] << std::endl;
    } else {
        std::cout <<"Don't find ... "<< std::endl;
    }

    std::cout << std::endl << "Test end!" << std::endl;
};
