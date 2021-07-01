//
// Created by MingR on 2021/7/1.
//
#include <stdio.h>
#include <stack>
#include <stdexcept>

using namespace std;

template <typename T> class CQueue {
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

static template <typename T> void CQueue<T>::appendTail(const T& element) {
    stack1.push(element);
}

static template <typename T> T CQueue<T>::deleteHead() {
    if (stack2.size() < = 0) {

        while (stack1.size() > 0) {
            T& data = stack1.top();
            stack1.pop();

            stack2.push(data);
        } // while end
    } // if end

    if (stack2.size() == 0) {
        throw logic_error("queue is empty");
    }

    T head = stack2.top();
    stack2.pop();

    return head;
}