#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *insert(int x, TreeNode *tree) {
    if (tree == NULL) {
        tree = (TreeNode*)malloc(sizeof(TreeNode));
        if (tree == NULL)
            printf("Out of space!\n");
        else {
            tree->val = x;
            tree->left = tree->right = NULL;
        }
    } else if (tree->left != NULL)
        tree->right = insert(x, tree->right);
    else tree->left = insert(x, tree->left);
    return tree;
}

/* 使用中序遍历打印树 */
void treeprint(TreeNode *root) {
    if (root != NULL) {
        treeprint(root->left);
        printf("%d ", root->val);
        treeprint(root->right);
    }
}

TreeNode *empty(TreeNode *root) {
    if (root != NULL) {
        empty(root->left);
        empty(root->right);
        free(root);
    }
    return NULL;
}

#endif
