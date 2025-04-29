#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode *node)
{
    struct ListNode *nxt = node->next;
    node->val = nxt->val;
    node->next = nxt->next;
    free(nxt);
}
