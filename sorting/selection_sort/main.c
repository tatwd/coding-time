extern void swap(int *a, int *b);

/**
 * 选择排序
 */
void selection_sort(int arr[], int n) {
  int i, j, min;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
        if (arr[j] < arr[min])
            min = j;
    }
    if (min != i)
        swap(&arr[i], &arr[min]);
  }
}
