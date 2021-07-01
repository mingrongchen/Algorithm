//
// Created by MingR on 2021/7/1.
//
#include <iostream>
#include <stack>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

/**
 * 利用栈倒序输出链表
 * @param pHead
 */
static void PrintListReversingly_Iteratively(ListNode* pHead) {
    if (!pHead) {
        return;
    }

    std::stack<ListNode*> nodes;
    ListNode* pNode = pHead;

    // 将链表节点顺序入栈
    for(;pNode->next; pNode = pNode->next) {
        nodes.push(pNode);
    }


    while(!nodes.empty()) {
        pNode = nodes.top();    // 获取栈顶元素
        printf("%d \t", pNode->data);
        nodes.pop();    // 出栈
    }
}

/**
 * 利用递归倒序输出链表
 * 问题：若链表太长容易出现栈溢出
 * 测试用例：链表为空、一个节点、多个节点等
 * @param pHead
 */
static void PrintListReversingly_Recursively(ListNode* pHead) {
    if (!pHead) {
        if (!pHead->next) {
            PrintListReversingly_Recursively(pHead->next);
        }
        printf("%d \t", pHead->data);
    }
}


