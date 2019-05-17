#include "../utils.h"
#include "binheap.h"

int main()
{
	int n = 10;
	int arr[] = { 16, 68, 24, 31, 32, 65, 26, 13, 21, 19 };
	priority_queue heap;

	heap = initialize(n);

	for (int i = 0; i < n; i++)
		insert(arr[i], heap);

	putarrln("%d ", heap->elements, n + 1);

	delete_min(heap);
	putarrln("%d ", heap->elements, n);

	decrease_key(5, 22, heap);
	putarrln("%d ", heap->elements, n);

	increase_key(1, 22, heap);
	putarrln("%d ", heap->elements, n);

	return 0;
}
