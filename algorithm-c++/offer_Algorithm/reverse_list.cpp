//
// Created by MingR on 2021/7/1.
//

#include <stdio.h>


typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;


/**
 * 反转链表
 * @param pHead
 * @return
 */
static ListNode* ReverseList(ListNode* pHead) {
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;

    while(pNode != NULL) {
        // 临时变量，保留当前节点下一个节点的位置
        ListNode* pNext = pNode->next;

        // 识别到尾节点
        if (pNext == NULL) {
            pReversedHead = pNode;
        }

        // 断开当前节点的下一个指向，重新指向上一个节点
        pNode->next = pPrev;

        // 保存当前节点，即反转链表第一个节点
        pPrev = pNode;
        // 当前节点指向之前保存的下一个节点位置
        pNode = pNext;
    }

    return pReversedHead;
}