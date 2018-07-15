#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>

typedef struct BinaryTreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    /* truct TreeNode(int x) : val(x), left(NULL), right(NULL) {} */
} TreeNode;

#endif
