//
// Created by MingR on 2021/3/19.
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

// 二叉树前序遍历递归算法，PLR
static void PreOrderTraverse(BiTree T) {
    printf("PreOrderTraverse begin ...\n");
    if (T == NULL) {
        return;
    }
    printf("%c\n", T->data);    // 显示节点数据，可以更改为对该节点操作
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

// 二叉树中序遍历递归算法，LPR
static void InOrderTraverse(BiTree T) {
    printf("InOrderTraverse begin ...\n");
    if (T == NULL) {
        return;
    }

    InOrderTraverse(T->lchild);
    printf("%c\n", T->data);    // 显示节点数据，可以更改为对该节点操作
    InOrderTraverse(T->rchild);
}

// 二叉树后序遍历递归算法，LPR
static void PostOrderTraverse(BiTree T) {
    printf("PostOrderTraverse begin ...\n");
    if (T == NULL) {
        return;
    }

    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c\n", T->data);    // 显示节点数据，可以更改为对该节点操作
}

// 按照前序PLR输入二叉树中节点的值（一个字符）
// #表示空数，构造二叉链表表示二叉树T
/* 按照前序PLR输入二叉树中节点的值（一个字符）
 * #表示空数，构造二叉链表表示二叉树T
 * 前序：AB#D##C##
 * 中序：#B#D#A#C#
 * 后序：###DB##CA
 */
static void CreatBiTree(BiTree *T) {
    printf("CreatBiTree begin ...\n");
    TElemType ch;
    scanf("%c", &ch);

    if (ch == '#') {
        *T = NULL;
        printf("*T = NULL ...\n");
    } else {
        // 创建一颗新树
        *T = (BiTree) malloc(sizeof(BiTNode));
        if (!*T) {
            exit(OVERFLOW);
        } else {
            (*T) -> data = ch;    // 生成根节点
            CreatBiTree(&(*T)->lchild);    // 递归构造左子树
            CreatBiTree(&(*T)->rchild);    // 递归构造右子树
        }
    }
} // CreatBiTree end

