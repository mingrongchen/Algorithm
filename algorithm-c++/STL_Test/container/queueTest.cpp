//
// Created by MingR on 2021/4/15.
//
#include <iostream>
#include <random>
#include <ctime>
#include <queue>

using namespace std;

typedef struct info {
    int age;
    int gender;
} Info, *PInfo;

static void test();
static void test2();


static void test() {
    Info tInfo;
    queue<Info> mQueue;
    int temp;

    srand(time(0));
    for (int i = 0; i < 6; i++) {
        temp = rand() % 100 + 1;
        cout << "i : " << i << " ,temp : " << temp <<  endl;
        tInfo.age = temp;
        tInfo.gender = temp;
        mQueue.push(tInfo);
    }

    cout << "my queue size : " << mQueue.size() << " ,top age : " << mQueue.back().age << endl;


    while (mQueue.size()) {
        cout << "out temp : " << mQueue.front().age <<  endl;
        mQueue.pop();
    }
}

static void test2() {
    Info tInfo;
    priority_queue<int> mPriorityQueue;
    int temp;

    srand(time(0));
    for (int i = 0; i < 6; i++) {
        temp = rand() % 100 + 1;
        cout << "i : " << i << " ,temp : " << temp <<  endl;;
        mPriorityQueue.push(temp);
    }

    cout << "my priority queue size : " << mPriorityQueue.size()  << endl;


    while (mPriorityQueue.size()) {
        cout << "out temp : " << mPriorityQueue.top() <<  endl;
        mPriorityQueue.pop();
    }
}
