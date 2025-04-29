#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (p == NULL && q == NULL)
        return 1;
    if (p == NULL || q == NULL)
        return 0;
    if (p->val != q->val)
        return 0;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
