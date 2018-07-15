#include <stdio.h>

/**
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 */
int singleNumber(int arr[], int n) {
    int result = 0;
    while (n > 0)
        result ^= arr[--n];
    return result;
}

/* testing it */
void test_singleNumber() {
    int arr1[] = { 0 };
    int arr2[] = { 1, 2, 1 };
    printf("%d %d\n",
        singleNumber(arr1, 1), singleNumber(arr2, 3));
}
