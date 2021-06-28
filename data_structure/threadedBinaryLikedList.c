//
// Created by MingR on 2021/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 二叉树的二叉线索存储结构定义
 * Link==0表示左右孩子指针
 * Thread==1表示指向前驱或后继的线索
 */
typedef enum {Link, Thread} PointerTag;

typedef char TElemType;

// 二叉线索存储节点结构定义代码
typedef struct BiTNode {
    TElemType data;    // 节点数据
    struct BiTNode *lchild, *rchild;    // 左右孩子指针
    PointerTag LTag;
    PointerTag RTag;    // 左右标志
} BiThrNode, *BiThrTree;

/*
 * 线索化的过程就是在遍历的过程中修改空指针的过程
 */
BiThrTree pre;    // 全局变量，始终指向刚刚访问过的节点

// 中序遍历线索化的递归函数代码
static void InThreading (BiThrTree p) {
    if (p) {
        InThreading(p->lchild);    // 递归左子树线索化

        // 左孩子为空，没有左孩子
        if (!p->lchild) {
            p->LTag=Thread;    // 前驱线索
            p->lchild=pre;    // 左孩子指向前驱
        }

        // 右孩子为空，没有右孩子
        if (!p->rchild) {
            p->rchild=Thread;    // 后继线索
            p->rchild=p;    // 前驱右孩子指向后继（即指向当前节点p）
        }

        pre = p;    // 保持pre全局指针指向p的前驱

        InThreading(p->rchild);    // 递归右子树线索化
    }
}

static void MyInThreading (BiThrTree p) {
    if (p) {
        MyInThreading(p->lchild);

        if (!p->lchild) {
            p->LTag = Thread;
            p->lchild = pre;
        }

        if (!pre->rchild) {
            pre->RTag = Thread;
            pre->rchild = p;
        }

        pre = p;

        MyInThreading(p->rchild);
    }
}

/*
 * T指向头节点，头结点左链lchild指向根节点，头结点右链rchild指向中序遍历的最后一个节点
 * 中旭遍历二叉线索链表表示的二叉树T
 */
static int InOrderTraverse_Thr (BiThrTree T) {
    BiThrTree p;
    p = T->lchild;    // p指向根节点

    // 空树遍历结束时，P==T
    while (p != T) {
        // 当LTag==0时，循环中序序列的第一个节点
        while (p->LTag==Link) {
            p = p->lchild;
        }

        printf("%c\n", p->data);    // 显示节点数据，可以更改为其它对节点操作

        while (p->RTag==Thread && p->rchild != T) {
            p = p->rchild;
            printf("%c\n", p->data);
        }

        p = p->rchild;    // p进至其右子树根
    }

    return 1;
}
