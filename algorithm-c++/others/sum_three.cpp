//
// Created by MingR on 2021/1/14.
//


/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all
 * unique triplets in the array which gives the sum of zero.
 * Note: Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c) The solution set
 * must not contain duplicate triplets.
 * 题目翻译：
 * 给定一个整型数组num，找出这个数组中满足这个条件的所有数字： num[i]+num[j]+num[k] = 0. 并且所有
 * 的答案是要和其他不同的，也就是说两个相同的答案是不被接受的。
 *
 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int> &num) {
//        // 边角问题处理
//        vector<int> ret;
//
//        if (numbers.size() <= 1) {
//            return ret;
//        }
//
//        // 新建一个map<key, value>来存储numbers里的元素和index
//        unordered_map<int, int> myMap;
//        for (int i = 0; i < numbers.size(); ++i) {
//            myMap[numbers[i]] = i;
//        }
//
//        for (int i = 0; i < numbers.size(); ++i) {
//            int rest_val = target - numbers[i];
//
//            if (myMap.find(rest_val) != myMap.end()) {
//                int index = myMap[rest_val];
//
//                // 同一个数字，pass
//                if (index == i) {
//                    continue;
//                }
//
//                if (index < i) {
//                    ret.push_back(index + 1);
//                    ret.push_back(i + 1);
//                    return ret;
//                } else {
//                    ret.push_back(i + 1);
//                    ret.push_back(index + 1);
//                    return ret;
//                }
//            }
//        }
//    }
//};
//
//static void test() {
//    int test_b[] = {1,7,15,27,99};
//    vector<int> arrayTest(test_b, test_b + sizeof(arrayTest) / sizeof(arrayTest[0]));
//
//    vector<int> result = Solution().twoSum(arrayTest, 22);
//
//    if (result.size() > 0) {
//        std::cout <<"Output: "<< result[0] << " , " <<result[1] << std::endl;
//    } else {
//        std::cout <<"Don't find ... "<< std::endl;
//    }
//
//    std::cout << std::endl << "Test end!" << std::endl;
//};
