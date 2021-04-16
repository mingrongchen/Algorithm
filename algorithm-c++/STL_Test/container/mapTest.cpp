//
// Created by MingR on 2021/4/15.
//
/**
 * set集合，内部结构为二叉树，红黑树
 *
 * 插入后有序
 */
#include <iostream>
#include <map>
#include <random>
#include <ctime>

using namespace std;

typedef struct info {
    int age;
    int gender;
} Info, *PInfo;

typedef pair<int, Info> CustomPair;

static void test();


static void test() {
    Info tInfo;
    map<int, Info> myMap;
    int temp;

    for (int i = 0; i < 6; i++) {
        temp = rand() % 100 + 1;
        cout << "i : " << i << " ,temp : " << temp <<  endl;
        tInfo.age = temp;
        tInfo.gender = temp;
        myMap.insert(CustomPair(i, tInfo));
    }

//    cout << "front : " << mySet.front().age << " ,back : " << mySet.back().age << endl;
    cout << "size : " << myMap.size() <<  endl;

    for (auto data = myMap.begin();  data != myMap.end(); ++data) {
        cout << "data index : " << data->first << " ,age : " << data->second.age << " ,gender : " << data->second.gender << endl;
    }

    myMap.clear();
    if (myMap.empty()) {
        cout << "myMap is empty ..." << endl;
    }

}

