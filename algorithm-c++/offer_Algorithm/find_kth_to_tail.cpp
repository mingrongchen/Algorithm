//
// Created by MingR on 2021/7/1.
//
#include <stdio.h>


typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;


/**
 * 题目描述：获取倒数第k个节点
 * @param pListHead
 * @param k
 * @return
 */
static ListNode* FindKthToTail(ListNode* pListHead, unsigned int k ) {

    if (pListHead == NULL && k <= 0) {
        return NULL;
    }

    ListNode *pAhead = pListHead;
    ListNode *pBehind = NULL;

    // 找到第k-1个节点
    for (unsigned int i = 0; i < k - 1; i++) {
        if (pAhead->next) {
            pAhead = pAhead->next;
        } else {
            return NULL;
        }
    }

    pBehind = pListHead;

    // 前指针指向末尾n，则后指针指向n-k+1的位置，就是倒数第k个
    for (;pAhead->next; pAhead = pAhead->next) {
        pBehind = pBehind->next;
    }

    return pBehind;
}