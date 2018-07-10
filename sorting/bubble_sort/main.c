extern void swap(int *a, int *b);

/**
 * 冒泡排序
 */
void bubble_sort(int arr[], int n) {
    int i, j, sorted;
    for (i = 0; i < n -1; i++) {
        sorted = 0;
        for (j = 0; j < n - i -1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j+1]);
                sorted = 1;
            }
        }
        if (!sorted)
            break; /* now array is sorted */
    }
}
