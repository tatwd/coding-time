#ifndef LIST_H
#define LIST_H

typedef struct node {
	int data;
	struct node *next;
} list_node;

list_node *init(int data, list_node *next);
void print_list(list_node *head);
list_node *array2list(int arr[], unsigned int size);
void empty(list_node *head);

#endif // LIST_H
