#ifndef STACK_H
#define STACK_H

typedef struct {
	int *elements;
	int logical_length;
	int alloc_length;
} stack;

void stack_new(stack *s, int alloc_length);
void stack_dispose(stack *s);
void stack_push(stack *s, int value);
int stack_pop(stack *s);

void stack_print(stack *s);

#endif
