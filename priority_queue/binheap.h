#ifndef _BINHEAP_H
#define _BINHEAP_H

struct heap_struct;
typedef struct heap_struct *priority_queue;

priority_queue initialize(int max);
int is_full(priority_queue heap);
int is_empty(priority_queue heap);
void insert(int value, priority_queue heap);
int delete_min(priority_queue heap);

/* others */
void decrease_key(int position, int dx,
                  priority_queue heap);
void increase_key(int position, int dx,
                  priority_queue heap);

#endif

/* one implement */
struct heap_struct
{
	int capacity;
	int size;
	int *elements;
};
