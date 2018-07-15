/**
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 */
int single_number(int arr[], int n) {
    int result = 0;
    while (n >= 0)
        result ^= arr[n--];
    return result;
}
