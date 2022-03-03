//
// Created by CMR on 2019/9/25.
//

#include "2-4-Link_List.h"

void link_test() {
    printf("Function: %s , Line: %d .\n", __FUNCTION__, __LINE__);
    PNode head;
    PNode p;
    PNode q;
    PNode t;
    int n;
    int a;
    scanf("%d", &n);
    head = NULL;    // 头指针为空

    for (int i = 1; i <= n; i++){
        scanf("%d", &a);
        // 动态申请一个空间，用来存放一个节点，并用临时节点p指向这个节点
        p = (PNode)malloc(sizeof(Node));
        p->data = a;
        p->next = NULL;
        if (head == NULL) {
            head = p;    // 如果这是第一个创建的节点，则将头指针指向这个节点
        } else {
            q->next = p;    // 如果不是第一个创建的节点，则将上一个节点的后继指针指向当前节点
        }

        q = p;    // 指针q也指向当前节点
    }

    // 插入链表
    printf("Insert a node: ");
    scanf("%d", &a);
    t = head;
    while (t != NULL) {
        if (t->next->data > a) {    // 如果当前节点下一个节点的值大于待插入数，将数插入到中间
            p = (PNode)malloc(sizeof(Node));
            p->data = a;
            p->next = t->next;    // 新增节点的后继指针指向当前节点的后继指针指向的节点
            t->next = p;    // 当前节点的后继指针指向新增节点
            break;    // 插入完毕退出循环
        }
        t = t->next;    // 继续下一个节点
    }

    // 插入链表完毕

    t = head;
    while (t != NULL){
        printf("%d  ", t->data);
        t = t->next;
    }

    getchar();
    printf("Function All Done. \n");

}