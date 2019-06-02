#include <stdio.h>

#include "queue.h"

int main(void)
{
	element_t arr[5] = { 1, 2, 3, 4, 5 };
	struct queue_t *queue = queue_new(5);

	for(int i = 0; i < sizeof(arr) / sizeof(element_t); i++)
		enqueue(queue, arr[i]);

	element_t v = dequeue(queue);
	printf("dequeue_value: %d front: %d rear: %d\n",
	       v, queue_front(queue), queue_rear(queue));

	for(int i = 0; i < queue_capacity(queue); i++)
		printf("%d\n", queue_data(queue, i));

	queue_free(queue);
	return 0;
}
