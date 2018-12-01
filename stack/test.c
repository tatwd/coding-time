#include <stdio.h>

#include "stack.h"

int main(void)
{
	int alloc_length = 5;
	stack s;

	stack_new(&s, alloc_length);
	stack_print(&s);

	for (int i = 0; i < alloc_length; ++i)
		stack_push(&s, i);
	stack_print(&s);

	stack_push(&s, 10);
	stack_print(&s);

	int val = stack_pop(&s);
	printf("pop %d\n", val);
	stack_print(&s);

	stack_dispose(&s);
	stack_print(&s);

	return 0;
}
