#include <math.h>

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
int countNodes(struct TreeNode *root)
{
    /* Solution 1 */
    /*
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
    */

    /* Solution 2 */
    if (root == NULL)
        return 0;
    struct TreeNode *lt = root->left, *rt = root->right;
    int h = 0;
    while (lt != NULL && rt != NULL) {
        lt = lt->left;
        rt = rt->right;
        h++;
    }

    /*
    now in `h` is completed
    2^(n+1) - 1
    */
    if (lt == NULL)
        return (int)pow(2, h + 1) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
