#include "../utils.h"
#include "binheap.h"

int main() {
    int n = 4;
    element_type arr[] = { 2, 4, 1, 3 };
    priority_queue heap;

    heap = initialize(n);
    for (int i = 0; i < n; i++)
        insert(arr[i], heap);
    putarrln("%d ", heap->elements, n + 1);

    return 0;
}
