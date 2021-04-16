//
// Created by MingR on 2021/4/14.
//
/**
 * https://en.cppreference.com/w/cpp/container/vector
 */
#include <iostream>
#include <vector>

using namespace std;

typedef struct info {
    int age;
    int gender;
} Info, *PInfo;


static void changeVector(vector<Info>&);
static void test();
static void test2();

static void test() {
    vector<Info> mInfo;
    Info tInfo;

    for (int i = 0; i < 3; i++) {
        tInfo.age = i;
        tInfo.gender = i;
        mInfo.push_back(tInfo);
    }

    cout << "front : " << mInfo.front().age << " ,back : " << mInfo.back().age << endl;
    cout << "size : " << mInfo.size() << " ,capactity : " << mInfo.capacity() << endl;

    for (auto data = mInfo.begin();  data != mInfo.end(); ++data) {
        cout << "data age: " << data->age << " ,gender: " <<  data->gender << endl;
    }

    // 默认深拷贝
    vector<Info> copyInfo = mInfo;

    for (auto data = copyInfo.begin();  data != copyInfo.end(); ++data) {
        cout << "copy data age: " << data->age << " ,gender: " <<  data->gender << endl;
    }

    mInfo[2].age = 100;
    mInfo[2].gender = 100;
    for (auto data = copyInfo.begin();  data != copyInfo.end(); ++data) {
        cout << "copy after data age: " << data->age << " ,gender: " <<  data->gender << endl;
    }

    for (auto data = mInfo.begin();  data != mInfo.end(); ++data) {
        cout << "after data age: " << data->age << " ,gender: " <<  data->gender << endl;
    }

    changeVector(mInfo);
    for (auto data = mInfo.begin();  data != mInfo.end(); ++data) {
        cout << "After data age: " << data->age << " ,gender: " <<  data->gender << endl;
    }

    copyInfo.clear();
    if (copyInfo.empty()) {
        cout << "copyInfo is empty ..." << endl;
    }
}

static void test2() {
    vector<int> mTest(10);

    mTest.insert(mTest.begin(), 100);
    mTest.insert(mTest.begin() + 1, 200);
    mTest.insert(mTest.begin() + 2, 300);

    for (auto item = mTest.begin(); item != mTest.end(); ++item) {
        cout << "item data : " << *item << endl;
    }

}


static void changeVector(vector<Info> &data) {
    for (auto item = data.begin();  item != data.end(); ++item) {
        item->age = -100;
        item->gender = -100;
    }
}