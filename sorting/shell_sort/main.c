/**
 * 希尔排序
 */
int shell_sort(int arr[], int n) {
    int i, j, increment, count;
    int current;

    for (increment = n/2; increment > 0; increment /= 2)
        for (i = increment; i < n; i++) {
            current = arr[i];
            for (
                j = i;
                j >= increment && arr[j - increment] > current;
                j -= increment
            ) {
                arr[j] = arr[j - increment];
            }
            arr[j] = current;
        }
    return count;
}
