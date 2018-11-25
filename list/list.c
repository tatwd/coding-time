#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

list_node *init(int data, list_node *next)
{
	list_node *node = malloc(sizeof(list_node));
	if (node == NULL) {
		printf("Out of space!\n");
		exit(-1);
	}
	node->data = data;
	node->next = next;
	return node;
}

void print_list(list *li)
{
	assert(li != NULL);
	printf("%d", li->data);
	list_node *ptr = li->next;
	while (ptr != NULL) {
		printf("->%d", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

list *array2list(int arr[], unsigned int size)
{
	/*
	// 尾插法
	list_node *head = init(arr[0], NULL);
	list_node *ptr = head;
	for (unsigned int i = 1; i < size; ++i) {
		ptr->next = init(arr[i], NULL);
		ptr = ptr->next;
	}
	*/

	// 头插法
	list_node *head = NULL;
	for (int i = size - 1; i >= 0; --i) {
		list_node *node = init(arr[i], head);
		head = node;
	}

	return head;
}

void empty(list *li)
{
	/*
	list_node *ptr = li->next;
	list_node *tmp = NULL;
	li->next = NULL;
	while (ptr != NULL) {
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	*/

	if (li == NULL) return;
	empty(li->next);
	free(li);
	li = NULL;
}

/*
 在第 `k` 个元素后插入数据 data
*/
void insert(list *li, int k, int data)
{
	assert(k >= 0 && li != NULL);

	if (k == 0) {
		li->next = init(li->data, li->next);
		li->data = data;
		return;
	}

	list_node *ptr = li;
	for (int i = 0; i < k - 1; ++i) {
		if (ptr->next != NULL) {
			ptr = ptr->next;
		} else {
			printf("The `index` is over the length of list!\n");
			exit(-1);
		}
	}
	ptr->next = init(data, ptr->next);
}

void remove_node(list *li, int x)
{
	assert(li != NULL);

	if (li->data == x) {
		/* TOFIX: need free deleted node */
		*li = *(li->next);
		return;
	}

	list_node *pre = li;
	list_node *ptr = li->next;
	while (ptr != NULL) {
		if (ptr->data == x) {
			pre->next = ptr->next;
			free(ptr);
		} else {
			pre = ptr;
		}
		ptr = pre->next;
	}
}

void remove_node2(list **li, list_node* x)
{
	assert(li != NULL && x != NULL);
	list_node **ptr = li;
	while ((*ptr) != x) {
		ptr = &(*ptr)->next;
	}
	*ptr = x->next;
	free(x);
}

list_node *find(list *li, int x)
{
	assert(li != NULL);
	list_node *ptr = li;
	while (ptr != NULL && ptr->data != x) {
		ptr = ptr->next;
	}
	return ptr;
}
