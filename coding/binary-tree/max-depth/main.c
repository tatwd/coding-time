#include "../binary_tree.h"

/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
int maxDepth(TreeNode *root) {
    if (root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}

/* test */
void test_maxDepth() {
    TreeNode *root;
    int i, arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    root = NULL;
    for (i = 0; i < 7; i++) {
        root = insert(arr[i], root);
    }
    /* the tree will be
        1
      /  \
     2    3
        /  \
       4    5
           / \
          6   7
    */
    printf("Maximum depth of the tree is %d\n", maxDepth(root));
    empty(root);
}
