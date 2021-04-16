//
// Created by MingR on 2021/4/15.
//

#include <iostream>
#include <stack>
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
    stack<Info> mStack;
    int temp;

    srand(time(0));
    for (int i = 0; i < 6; i++) {
        temp = rand() % 100 + 1;
        cout << "i : " << i << " ,temp : " << temp <<  endl;
        tInfo.age = temp;
        tInfo.gender = temp;
        mStack.push(tInfo);
    }

    cout << "my stack size : " << mStack.size() << " ,top age : " << mStack.top().age << endl;

//    for (auto i = 0; i < mStack.size(); ++i) {
//        cout << "out i : " << i << " ,temp : " << mStack.top().age <<  endl;
//        mStack.pop();
//    }

    while (mStack.size()) {
        cout << "out temp : " << mStack.top().age <<  endl;
        mStack.pop();
    }


}
