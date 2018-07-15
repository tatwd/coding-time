#include "../binary_tree.h"

/**
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */
int isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL) return 1;
    if (p == NULL || q == NULL) return 0;
    if (p->val != q->val) return 0;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/* testing it */
void  test_isSameTree() {
    TreeNode *root;
    int i, arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    root = NULL;
    for (i = 0; i < 7; i++) {
        insert(arr[i], root);
    }
    treeprint(root);
}
