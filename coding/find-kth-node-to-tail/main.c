#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	int data;
	struct Node *next;
} ListNode;

ListNode *init(int data, ListNode *next) {
	ListNode *node = malloc(sizeof(ListNode));
	node->data = data;
	node->next = next;
	return node;
}

/*
求链表倒数第 k 个节点
*/
ListNode *find_kth_to_tail(ListNode *head, unsigned int k)
{
	if (head == NULL)
		return NULL;

	if (k == 0)
		return NULL;

	ListNode *aptr = head;
	ListNode *bptr = NULL;

	for (unsigned int i = 0; i < k - 1; ++i) {
		aptr = aptr->next;
		if (aptr == NULL) /* k > list.length */
			return NULL;
	}

	bptr = head;

	while (aptr->next != NULL) {
		aptr = aptr->next;
		bptr = bptr->next;
	}
	return bptr;
}

int main(int argc, char const *argv[])
{
	ListNode *head = init(0, NULL);
	ListNode *ptr = head;
	for (int i = 1; i < 5; ++i) {
		ptr->next = init(i, NULL);
		ptr = ptr->next;
	}

	ListNode *node = find_kth_to_tail(head, 6);

	/* print list */
	ptr = node;
	while(ptr != NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	return 0;
}
