//
// Created by MingR on 2021/4/15.
//
/**
 * 算法库4大类
 * 1、非修改式序列算法
 * 2、修改式序列算法
 * 3、排序和相关算法
 * 4、通用数字算法
 */

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct info {
    int age;
    int gender;
} Info, *PInfo;

static void test();
template <class T>
static void FillValue (T& vect, int first, int last);
static void print(int elem);
static void for_each_test();
static bool isEven(int elem);
static void count_test();
static bool AbsLess(int elem1, int elem2);
static void min_test();
static void find_test();


template <class T>
class Multiple {
private:
    T theValue;
public:
    // 构造函数
    Multiple(const T& v):theValue(v) {

    }
    // 仿函数
    void operator()(T& elem) const {
        elem *= theValue;
    }
};

class SUM {
private:
    long sum_D;
public:
    // 构造函数
    SUM() : sum_D(0){

    }

    // 仿函数
    void operator() (int elem) {
        sum_D += elem;
    }

    // 返回求解的和
    operator double() {
        return static_cast<double>(sum_D);
    }
};

static void for_each_test() {
    vector<int> myVector;
    FillValue(myVector, 1, 10);
    for_each(myVector.begin(), myVector.end(), print);
    cout << endl;
    // 所有元素乘积测试
//    for_each(myVector.begin(), myVector.end(), Multiple<int>(2));
//    for_each(myVector.begin(), myVector.end(), print);
//    cout << endl;

    // 求和测试
    double sum = for_each(myVector.begin(), myVector.end(), SUM());
    cout << "The Sum : " << sum << endl;
}

template <class T>
void FillValue (T& vect, int first, int last) {
    srand(time(0));
    int temp;
    if (last >= first) {
        for (auto i = first; i <= last; ++i) {
            temp = rand() % 100 + 1;
            cout << "i : " << i << " ,temp : " << temp <<  endl;
            vect.insert(vect.end(), temp);
        }
    } else {
        cout << "The indexes is error: last < first. " << endl;
    }
}

static bool isEven(int elem) {
    return elem % 2 == 0;
}

void print(int elem) {
    cout << elem << " ";
}

static void count_test() {
    vector<int> myVector;
    FillValue(myVector, 1, 10);
    for_each(myVector.begin(), myVector.end(), print);
    cout << endl;
    // 统计偶数的个数
    int evenCount = count_if(myVector.begin(), myVector.end(), isEven);

    cout << "Even count is : " << evenCount << endl;
}

// 使用绝对值进行比较，计算最小值
static bool AbsLess(int elem1, int elem2) {
    return abs(elem1) < abs(elem2);
}

static void min_test() {
    vector<int> myVector;
    FillValue(myVector, 1, 10);
    for_each(myVector.begin(), myVector.end(), print);
    cout << endl;

    cout << "minimum: " << *min_element(myVector.begin(), myVector.end()) << endl;
    cout << "minimum of absolute value: " << *min_element(myVector.begin(), myVector.end(), AbsLess) << endl;
}

static void find_test() {
    /**
     * 返回值都为Iterator，迭代器
     * find、find_if ：搜寻第一个匹配元素
     * search_n：搜寻前n个连续匹配值
     * serach：搜寻第一个子区间
     * find_end：搜寻最后一个子区间
     * find_first_of：搜寻某些元素第一次出现的位置
     */
    vector<int> myVector;
    FillValue(myVector, 1, 10);
    for_each(myVector.begin(), myVector.end(), print);
    cout << endl;

    vector<int>::iterator pos;
    pos = find_if(myVector.begin(), myVector.end(), bind2nd(greater<int>(), 30));
    cout << "The position of the first element being larger than 30 : " << distance(myVector.begin(), pos) + 1 << endl;
}

void test() {
    find_test();
}




