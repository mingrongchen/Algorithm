//
// Created by MingR on 2021/6/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef char TElemType;

// 二叉链表结构定义代码
typedef struct BiTNode {
    TElemType data;    // 节点数据
    struct BiTNode *lchild, *rchild;    // 左右孩子指针
} BiTNode, *BiTree;

/**
 *
 * @param T
 * @param key
 * @param f:指向T的双亲，初始调用为NULL
 * @param p
 * @return
 */
static int SearchBST(BiTree T, int key, BiTree f, BiTree *p) {

    if (!T) {
        *p = f;
        return -1;
    } else if (key == T->data) {
        *p = T;
        return 1;
    } else if (key < T->data) {
        return SearchBST(T->lchild, key, T, p);    // 在左子树继续查找
    } else {
        return SearchBST(T->rchild, key, T, p);    // 在右子树继续查找
    }




}