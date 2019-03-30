#include <stdio.h>

/* extern void swap(int *a, int *b); */
#include "utils.h"

/**
 * 冒泡排序
 */
void bubble_sort(int arr[], int n) {
    /*
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
            break;
    }
	*/
	/*
	int i, j, sorted;
	for (i = n - 1; i > 0; i--) {
		sorted = 0;
		for (j = 0; j < i; j++) {
		if (arr[j] > arr[j + 1]) {
			swap(&arr[j], &arr[j+1]);
			sorted = 1;
		}
		}
		if (!sorted)
			break;
	}
	*/

	/* 递归版 */
	int i, sorted = 0;
	for (i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			swap(&arr[i], &arr[i + 1]);
			sorted = 1;
		}
	}
	if (!sorted)
		return;
	bubble_sort(arr, n - 1);
}

int main(void)
{
	int arr[] = {4, 2, 1, 5, 7, 3};
	bubble_sort(arr, 6);
	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
