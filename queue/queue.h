#ifndef QUEUE_H
#define QUEUE_H

#ifndef element_t
#define element_t int
#endif /* element_t  */

struct queue_t; /* 声明 queue_t 类型 */

struct queue_t *queue_new(int); /* new a queue with capacity */
void queue_free(struct queue_t *); /* free the queue */
int queue_size(struct queue_t *);
int queue_capacity(struct queue_t *);
int queue_front(struct queue_t *);
int queue_rear(struct queue_t *);
element_t queue_data(struct queue_t *, int);
void enqueue(struct queue_t *, element_t); /* 入队 */
element_t dequeue(struct queue_t *); /* 出队 */

#endif /* QUEUE_H */
