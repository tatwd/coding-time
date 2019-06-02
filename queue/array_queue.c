#include "queue.h"

#include <stdlib.h>

struct queue_t {
	int front;
	int rear;
	int capacity;
	int size;
	element_t *data;
};

struct queue_t *queue_new(int capacity)
{
	struct queue_t *queue = malloc(sizeof(struct queue_t));
	queue->front = 0;
	queue->rear = -1;
	queue->capacity = capacity;
	queue->size = 0;
	queue->data = calloc(sizeof(element_t), capacity);
	return queue;
}

void queue_free(struct queue_t *queue)
{
	free(queue->data);
	free(queue);
}

int queue_size(struct queue_t *queue)
{
	return queue->size;
}

int queue_capacity(struct queue_t *queue)
{
	return queue->capacity;
}

int queue_front(struct queue_t *queue)
{
	return queue->front;
}

int queue_rear(struct queue_t *queue)
{
	return queue->rear;
}

element_t queue_data(struct queue_t *queue, int index)
{
	if (index < 0 || index > queue->capacity)
		return -1;
	return queue->data[index];
}

void enqueue(struct queue_t *queue, element_t x)
{
	if (queue->size == queue->capacity)
		return;
	int rear = queue->rear;
	if (++rear >= queue->capacity)
		rear = 0;
	queue->rear = rear;
	queue->data[rear] = x;
	queue->size += 1;
}

element_t dequeue(struct queue_t *queue)
{
	if (queue->size == 0)
		return -1;
	int front = queue->front;
	queue->front += (front + 1) < queue->capacity ? 1: -front;
	queue->size -= 1;
	return queue->data[front];
}
