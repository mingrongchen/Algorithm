//
// Created by MingR on 2021/4/15.
//
/**
 * set集合，内部结构为二叉树，红黑树
 *
 * 插入后有序
 *
 *
 */
#include <iostream>
#include <set>
#include <random>
#include <ctime>

using namespace std;

typedef struct info {
    int age;
    int gender;
} Info, *PInfo;

static void test();


static void test() {
    Info tInfo;
    set<int> mySet;
    int temp;

    for (int i = 0; i < 6; i++) {
        temp = rand() % 100 + 1;
        cout << "i : " << i << " ,temp : " << temp <<  endl;
        mySet.insert(temp);
    }

//    cout << "front : " << mySet.front().age << " ,back : " << mySet.back().age << endl;
    cout << "size : " << mySet.size() <<  endl;

    for (auto data = mySet.begin();  data != mySet.end(); ++data) {
        cout << "data : " << *data << endl;
    }

    mySet.clear();
    if (mySet.empty()) {
        cout << "mySet is empty ..." << endl;
    }

}


