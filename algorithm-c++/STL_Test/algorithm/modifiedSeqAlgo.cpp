//
// Created by MingR on 2021/4/15.
//

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct info {
    int age;
    int gender;
} Info, *PInfo;

static void test();
template <class T>
static void FillValue (T& vect, int first, int last);
static void print(int elem);

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

void test() {
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

void print(int elem) {
    cout << elem << " ";
}





