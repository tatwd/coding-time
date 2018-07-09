#define left_child(i) (2*(i) + 1)

extern void swap(int *a, int *b);

void perc_down(int arr[], int i, int n) {
    int child;
    int current;

    for (current = arr[i]; left_child(i) < n; i = child) {
        child = left_child(i);
        if (child != n - 1 && arr[child + 1] > arr[child])
            child++;
        if (current < arr[child])
            arr[i] = arr[child];
        else
            break;
    }
    arr[i] = current;
}

void heap_sort(int arr[], int n) {
    int i;

    /* build heap */
    for (i = n/2; i >= 0; i--)
        perc_down(arr, i, n);

    /* putarrln("%d ", arr, n); */

    for (i = n-1; i > 0; i--) {
        /* delete max */
        swap(&arr[0], &arr[i]);
        perc_down(arr, 0, i);
    }
}
