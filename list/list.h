#ifndef LIST_H
#define LIST_H

/*
 without head pointer
*/

typedef struct node {
	int data;
	struct node *next;
} list_node;

typedef struct node list;

list_node *init(int, list_node *);
void print_list(list *);
list *array2list(int[], unsigned int size);
void empty(list *);
void insert(list *, int, int);
void remove_node(list *, int);
void remove_node2(list **, list_node *);
list_node *find(list *, int);

#endif // LIST_H
