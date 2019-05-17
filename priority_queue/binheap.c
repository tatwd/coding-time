#include <stdio.h>
#include <stdlib.h>

#include "binheap.h"

#define MIN_VALUE -1024

/* initialize a priority queue */
priority_queue initialize(int max)
{
	priority_queue heap;

	heap = (priority_queue)malloc(sizeof(struct heap_struct));
	if (heap == NULL) {
		printf("Out of space!\n");
		return NULL;
	}

	heap->elements = (int *)malloc(
		(max + 1) * sizeof(int));

	if (heap->elements == NULL) {
		printf("Out of space!\n");
		return NULL;
	}

	heap->capacity = max;
	heap->size = 0;
	heap->elements[0] = MIN_VALUE;

	return heap;
}

/* check if the heap is full */
int is_full(priority_queue heap)
{
	return heap->size == heap->capacity;
}

/* check if the heap is empty */
int is_empty(priority_queue heap)
{
	return heap->size == 0;
}

/* insert a element to the heap */
void insert(int value, priority_queue heap)
{
	int i;

	if (is_full(heap)) {
		printf("Priority queue is full!\n");
		return;
	}

	/* 先检查父节点（heap->elements[i/2]）是否大于待插入节点 */
	for (i = ++heap->size; heap->elements[i / 2] > value; i /= 2)
		heap->elements[i] = heap->elements[i / 2]; /* 上滤 */
	heap->elements[i] = value;
}

/* delete the min value of priority queue */
int delete_min(priority_queue heap)
{
	int i, j;
	int min_value, last_value;

	if (is_empty(heap)) {
		printf("Priority queue is empty!\n");
		return heap->elements[0];
	}

	min_value = heap->elements[1];
	last_value = heap->elements[heap->size];

	heap->size--;

	/* `i` is root node index */
	for (i = 1; i * 2 <= heap->size; i = j) {
		j = i * 2; /* `j` is left child index */

		if (j != heap->size && heap->elements[j]
		                     > heap->elements[j + 1])
			j++;

		if (last_value > heap->elements[j])
			heap->elements[i] = heap->elements[j]; /* 下滤*/
		else
			break;
	}
	heap->elements[i] = last_value;
	return min_value;
}

/* Decrease the value of `position` by `dx` */
void decrease_key(int position, int dx,
                  priority_queue heap)
{
	int new_value;
	int i;

	if (is_empty(heap)) {
		printf("Priority queue is empty!\n");
		return;
	}

	if (position > heap->size || position < 1) {
		printf("The `position` value overflow the range of heap!\n");
		return;
	}

	new_value = heap->elements[position] - dx;
	for (i = position; heap->elements[i / 2] > new_value; i /= 2)
		heap->elements[i] = heap->elements[i / 2];
	heap->elements[i] = new_value;
}

/* Increase the value of `position` by `dx` */
void increase_key(int position, int dx,
                  priority_queue heap)
{
	int new_value;
	int i, j;

	if (is_empty(heap)) {
		printf("Priority queue is empty!\n");
		return;
	}

	if (position > heap->size || position < 1) {
		printf("The `position` value overflow the range of heap!\n");
		return;
	}

	new_value = heap->elements[position] + dx;
	for(i = position; i * 2 <= heap->size; i = j) {
		j = i * 2;
		if (j != heap->size && heap->elements[j]
		                     > heap->elements[j + 1])
			j++;

		if (heap->elements[j] < new_value)
			heap->elements[i] = heap->elements[j];
		else
			break;
	}
	heap->elements[i] = new_value;
}
