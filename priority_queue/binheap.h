#ifndef _BINHEAP_H
#define _BINHEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef int element_type;

struct heap_struct {
  int capacity;
  int size;
  element_type *elements;
};
typedef struct heap_struct *priority_queue;

priority_queue initialize(int max);
int isfull(priority_queue heap);
void insert(element_type value, priority_queue heap);

/* implementations */

priority_queue initialize(int max) {
  priority_queue heap;

  heap = (priority_queue)malloc(sizeof(struct heap_struct));
  if (heap == NULL) {
    printf("Out of space!\n");
    return NULL;
  }

  heap->elements = (element_type*)malloc(
    (max + 1) * sizeof(element_type)
  );

  if (heap->elements == NULL) {
    printf("Out of space!\n");
    return NULL;
  }

  heap->capacity = max;
  heap->size = 0;
  heap->elements[0] = -1;

  return heap;
}

int isfull(priority_queue heap) {
  return heap->size == heap->capacity;
}

void insert(element_type value, priority_queue heap) {
  int i;

  if (isfull(heap)) {
    printf("Priority queue is full!\n");
    return;
  }

  for (i = ++heap->size; heap->elements[i/2] > value; i /= 2)
    heap->elements[i] = heap->elements[i/2];
  heap->elements[i] = value;
}

#endif

/*

    1
  /  \
 2    3

*/
