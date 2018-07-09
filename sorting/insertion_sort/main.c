/**
 * 插入排序
 */
void insertion_sort(int arr[], int n) {
    int i, j, current;
    for (i = 1; i < n; i++) {
        current = arr[i];
        for (
            j = i;
            j > 0 && arr[j - 1] > current;
            j--
        ) {
            arr[j] = arr[j - 1];
        }
        arr[j] = current;
    }
}

/*
void insertion_sort(int *arr, int n) {
  int *p1, *p2, current;
  for (p1 = arr + 1; p1 < arr+n; p1++) {
    current = *p1;
    for (
      p2 = p1;
      p2 > arr && *(p2-1) > current;
      p2--
    ) {
      *p2 = *(p2 - 1);
    }
    *p2 = current;
  }
  p1 = p2 = NULL;
}
*/
