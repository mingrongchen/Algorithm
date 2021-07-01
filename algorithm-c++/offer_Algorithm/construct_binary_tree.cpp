//
// Created by MingR on 2021/7/1.
//
#include <iostream>
#include <stdexcept>

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;


/**
 * 找到左右子树前序、中序遍历的序列
 * @param startPreorder:前序遍历第一个指针
 * @param endPreorder：前序遍历最后一个指针
 * @param startInorder：中序遍历第一个指针
 * @param endInorder：中序遍历最后一个指针
 * @return
 */
static BinaryTreeNode* ConstrucCore (int* startPreorder, int* endPreorder, int* startInorder, int* endInorder) {
    int rootValue = startPreorder[0];    // 前序遍历序列的第一个数字是根节点的值

    BinaryTreeNode* root;
    root->data = rootValue;
    root->left = root->right = NULL;

    // 递归边界条件
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        } else {
            throw std::logic_error("Invalid input.");
        }
    }

    int *rootInorder = startInorder;    // 中序遍历中找到根节点的值
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        ++rootInorder;
    }

    if (rootInorder == endInorder && *rootInorder != rootValue) {
        throw std::logic_error("Invalid input.");
    }

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;

    // 如果左子树存在且长度大于0
    if (leftLength > 0) {
        // 构建左子树
        root->left = ConstrucCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }

    if (leftLength < endPreorder - startPreorder) {
        // 构建右子树
        root->right = ConstrucCore(leftPreorderEnd + 1, leftPreorderEnd, rootInorder + 1, endInorder);
    }

    return root;
}

/**
 * eg: 前序1、2、4、7、3、5、6、8；后序：4、7、2、1、5、3、8、6
 *
 * 根据前序和中序遍历构造一颗二叉树
 * 利用递归的思想
 * 测试用例：普通二叉树、特殊二叉树（只有左子树）、特殊输入NULL
 * @param preorder
 * @param inorder
 * @param length
 * @return
 */
static BinaryTreeNode* Construct(int * preorder, int* inorder, int length) {
    if (preorder || inorder || length < 0) {
        return NULL;
    }

    return ConstrucCore(preorder, preorder + length -1, inorder, inorder + length -1);
}