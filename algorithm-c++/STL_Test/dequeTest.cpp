//
// Created by MingR on 2021/4/14.
//
/**
 * deque采用动态数组来管理序列中的元素，提供随机存取，几乎和vector类似的接口。
 * 重要特性：在deque两端放置和删除元素是高效的，头尾均开放，可以实现在序列两端快速插入和删除
 * deque与vector相比
 * 1、deque两端插入删除高效，但是速度很慢，需要移动相关所有元素。
 * 2、deque存取元素稍慢
 * 3、deque迭代器指针是智能指针
 * 4、内存受限的系统中，deque可以包含更多元素，由于deque使用多块内存
 * 5、deque不支持内存重分配时机的控制
 * 6、deque内存区块不是好用会被释放
 *
 */
#include <iostream>
#include <deque>

using namespace std;

typedef struct info {
    int age;
    int gender;
} Info, *PInfo;

static void test() {
    Info tInfo;
    deque<Info> myDeque;

    for (int i = 0; i < 3; i++) {
        tInfo.age = i;
        tInfo.gender = i;
//        myDeque.push_back(tInfo);
        myDeque.push_front(tInfo);
    }

    cout << "front : " << myDeque.front().age << " ,back : " << myDeque.back().age << endl;
    cout << "size : " << myDeque.size() <<  endl;

    for (auto data = myDeque.begin();  data != myDeque.end(); ++data) {
//        cout << "data age: " << data->age << " ,gender: " <<  data->gender << endl;
        Info temp = *data;
        cout << "data age: " << temp.age << " ,gender: " <<  temp.gender << endl;
    }

    myDeque.clear();
    if (myDeque.empty()) {
        cout << "myDeque is empty ..." << endl;
    }



}

