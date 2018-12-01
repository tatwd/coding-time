#include <stdio.h>

#include "bsearch.h"

int main(void)
{
	int key, arr[] = { 1, 2, 3, 4, 5, 6 };
	int n = 6, index;

	for (int i = 1; i <= n+1; ++i) {
		key = i;
		printf("[find %d] ", key);

		index = bsearch1(key, arr, n);
		printf("bsearch1: %d, ", index);

		index = bsearch2(&key, arr, n, sizeof(int));
		printf("bsearch2: %d, ", index);

		index = bsearch3(&key, arr, n, sizeof(int), int_cmp);
		printf("bsearch3: %d\n", index);
	}

	return 0;
}
