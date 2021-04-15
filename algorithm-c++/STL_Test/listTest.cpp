//
// Created by MingR on 2021/4/14.
//
/**
 * list与vector相比
 * list采用双向链表结构，在任何位置插入删除动作非常迅速
 * 1、list不支持随机存取，没有下标操作符和at()函数。
 * 2、list采用双向链表结构，在任何位置插入删除动作非常迅速。
 * 3、list没有提供容量、空间重新分配等操作函数，每个元素有自己的内存
 * 4、list提供了特殊成员函数，专门用于移动元素，和同名算法相比，速度更快。
 * merge()、remove()、remove_if()、sort()、splice()、unique()
 *
 */

#include <iostream>
#include <list>

using namespace std;

typedef struct info {
    int age;
    int gender;
} Info, *PInfo;

static void test() {
    Info tInfo;
    list<Info> myList;

    for (int i = 0; i < 3; i++) {
        tInfo.age = i;
        tInfo.gender = i;
        myList.push_back(tInfo);
    }

    cout << "front : " << myList.front().age << " ,back : " << myList.back().age << endl;
    cout << "size : " << myList.size() <<  endl;

    for (auto data = myList.begin();  data != myList.end(); ++data) {
//        cout << "data age: " << data->age << " ,gender: " <<  data->gender << endl;
        Info temp = *data;
        cout << "data age: " << temp.age << " ,gender: " <<  temp.gender << endl;
    }

    myList.reverse();
    for (auto data = myList.begin();  data != myList.end(); ++data) {
        cout << "reverse after data age: " << data->age << " ,gender: " <<  data->gender << endl;
    }

    Info tempOne = {100, 100};
    myList.assign(5, tempOne);
    for (auto data = myList.begin();  data != myList.end(); ++data) {
        cout << "assign after data age: " << data->age << " ,gender: " <<  data->gender << endl;
    }

//    myList.unique();
//    for (auto data = myList.begin();  data != myList.end(); ++data) {
//        cout << "unique after data age: " << data->age << " ,gender: " <<  data->gender << endl;
//    }


    myList.clear();
    if (myList.empty()) {
        cout << "myList is empty ..." << endl;
    }



}