//
// Created by MingR on 2021/7/1.
//

#include <stdio.h>


typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

/**
 * 合并两个有序链表
 * @param pHead1
 * @param pHead2
 * @return
 */
static ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
    // 递归边界返回条件
    if (pHead1 == NULL) {
        return pHead2;
    } else if (pHead2 == NULL) {
        return pHead1;
    }

    ListNode* pMergedHead = NULL;

    if (pHead1->data < pHead2->data) {
        pMergedHead = pHead1;
        pMergedHead->next = Merge(pHead1->next, pHead2);
    } else {
        pMergedHead = pHead2;
        pMergedHead->next = Merge(pHead1, pHead2->next);
    }

    return pMergedHead;
}