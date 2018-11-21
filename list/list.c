#include <stdlib.h>
#include <stdio.h>

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

void print_list(list_node *head)
{
	if (head == NULL) return;
	printf("%d", head->data);
	list_node *ptr = head->next;
	while (ptr != NULL) {
		printf("->%d", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

list_node *array2list(int arr[], unsigned int size)
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

void empty(list_node *head)
{
	if (head == NULL) return;
	empty(head->next);
	free(head);
}
