#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

void stack_new(stack *s, int alloc_length)
{
	s->alloc_length = alloc_length;
	s->logical_length = 0;
	s->elements = malloc(sizeof(int) * alloc_length);
	assert(s->elements != NULL);
}

void stack_dispose(stack *s)
{
	free(s->elements);
	s->elements = NULL;
	s->logical_length = 0;
	s->alloc_length = 0;
}

void stack_push(stack *s, int value)
{
	assert(s != NULL);
	if (s->logical_length == s->alloc_length) {
		/*
		Make it dynamic!

		The `realloc` function will copy the old values to a new address
		on heap, and then it will free the old addree.
		*/
		s->alloc_length *= 2;
		s->elements = realloc(s->elements, s->alloc_length * sizeof(int));
		assert(s->elements != NULL);

		/*
		printf("The stack is full!\n");
		return;
		*/
	}
	s->elements[s->logical_length++] = value;
}

int stack_pop(stack *s)
{
	assert(s != NULL && s->logical_length > 0);
	return s->elements[--s->logical_length];
}

void stack_print(stack *s)
{
	printf("(%p){ logical_length: %d,\n\talloc_length: %d,\n\telements(%p): [",
		s, s->logical_length, s->alloc_length, s->elements);
	int i;
	for (i = 0; i < s->logical_length - 1; ++i)
		printf("%d, ", s->elements[i]);
	if (i != 0)
		printf("%d", s->elements[i]);
	printf("] }\n");
}
