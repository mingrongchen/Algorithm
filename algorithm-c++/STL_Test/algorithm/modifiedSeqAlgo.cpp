//
// Created by MingR on 2021/4/19.
//
/**
 * 算法库4大类
 * 1、非修改式序列算法
 * 2、修改式序列算法
 * 3、排序和相关算法
 * 4、通用数字算法
 *
 * 改变容器中元素的值两种方法
 * 1、使用迭代器遍历序列过程中直接改变元素的值
 * 2、在元素复制过程中，改变元素的值
 * 主要包括：复制、转换、互换、赋值、替换、逆转、旋转、排序8种
 */

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <iterator>

using namespace std;

template <class T>
static void FillValue (T& vect, int first, int last);
static void test();
static void copy_test();
static void print(int);
static void transform_test();
static void swap_test();
static void fill_test();
static int Fibonacci(void);
static void replace_test();
// 未实现
static void reverse_test();


static void print(int elem) {
    cout << elem << " ";
}

template <class T>
void FillValue (T& vect, int first, int last) {
    srand(time(0));
    int temp;
    if (last >= first) {
        for (auto i = first; i <= last; ++i) {
            temp = rand() % 100 + 1;
//            cout << "i : " << i << " ,temp : " << temp <<  endl;
            vect.insert(vect.end(), temp);
        }
    } else {
        cout << "The indexes is error: last < first. " << endl;
    }
}


/**
 * copy：是正向遍历序列
 * copy_backward：函数是你想遍历序列
 *
 * 如果实现两个容器间所有元素的复制，使用assign()算法
 */
static void copy_test() {
    vector<int> myVector;
    FillValue(myVector, 1, 10);
    for_each(myVector.begin(), myVector.end(), print);
    cout << endl;
    list<int> l1, l2;

    copy(myVector.begin(), myVector.end(), back_inserter(l1));
    cout << "list l1 :" << endl;
    for_each(l1.begin(), l1.end(), print);
    cout << endl;

    l2 = l1;
    cout << "list l2 : " << endl;
    copy(l2.begin(), l2.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    copy_backward(myVector.begin() + 2, myVector.begin() + 6, l2.end());
    cout << "list l2(modified) : " << endl;
    copy(l2.begin(), l2.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

/**
 * 将源区间的元素赋值至目标区间，复制和修改一气呵成。
 * 还可以将两个区间元素合并，并肩结果写到目标区间。
 *
 */
static void transform_test() {
    vector<int> v1;
    FillValue(v1, 1, 10);
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    list<int> l2, l3;

    // l2中元素分别乘以-1
    transform(v1.begin(), v1.end(), back_inserter(l2), negate<int>());
    cout << "list l2 : ";
    for_each(l2.begin(), l2.end(), print);
    cout << endl;

    // l2中元素风别乘以10
    transform(l2.begin(), l2.end(), l2.begin(), bind2nd(multiplies<int>(), 10));
    cout << "lsit l2 (*10) : ";
    for_each(l2.begin(), l2.end(), print);
    cout << endl;

}

/**
 * swap：交换两个类型相同的容器对象
 * swap_ranges：交换两个容器中的部分元素
 */
static void swap_test() {
    vector<int> v1;
    vector<int> v2;
    FillValue(v1, 1, 10);
    FillValue(v2, 1, 10);
    transform(v2.begin(), v2.end(), v2.begin(), bind2nd(multiplies<int>(), 10));
    cout << "vector 1 : ";
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    cout << "vector 2 : ";
    for_each(v2.begin(), v2.end(), print);
    cout << endl;

    swap(v1, v2);
    cout << "After swap ..." << endl;
    cout << "vector 1 : ";
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    cout << "vector 2 : ";
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
}

static int Fibonacci(void) {
    static int r;
    static int f1 = 0;
    static int f2 = 1;
    r = f1 + f2;
    f1 = f2;
    f2 = r;
    return f1;
}

/**
 * 容器赋值
 * fill_n和generate_n只能指定区间前的那个数值赋值
 * fill和fill_n用于给每个元素赋予相同的数值
 * generate()和generate_n()在执行时会调用函数的子进程或仿函数
 *
 *
 */
static void fill_test() {
    vector<int> v1;
    vector<int> v2(5,0), v3(6,0);
    int dim[] = {1,2,3,4,5,6,7,8,9};
    v1.assign(dim, dim + 9);
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    fill(v1.begin(), v1.begin() + 4, 9);
    cout << "fill : ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    fill_n(v1.begin(), 5, 20);
    cout << "fill_n : ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    /*------------*/
    generate(v2.begin(), v2.end(), rand);
    cout << "generate(rand) :";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    generate_n(v2.begin(), 3, rand);
    cout << "generate_n(3 rand) :";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    generate_n(v2.begin(), 6, Fibonacci);
    cout << "generate_n(6 Fibonacci) :";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

/**
 * replace：
 * replace_if():
 */
static void replace_test() {
    vector<int> v1;
    int dim[] = {1,2,3,4,5,6,7,8,9};
    v1.assign(dim, dim + 9);
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    replace(v1.begin(), v1.end(), 7, 99);
    cout << "replace : ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    replace_if(v1.begin(), v1.end(), bind2nd(less<int>(), 5), 11);
    cout << "replace_if : ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
}

/**
 * reverse:
 * reverse_copy:
 */
static void reverse_test() {



}

static void test() {
    replace_test();
}


