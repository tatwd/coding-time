#include <stdio.h>
#include <stdlib.h>

/* 合并两段有序的数组 */
/*
void merge(int arr[], int n)
{
	int *tmp = malloc(n * sizeof(int));
	int mid = n / 2;
	int i, j, k;
	i = 0;
	j = mid + 1;
	k = 0;
	while(i <= mid && j < n) {
		tmp[k++] = arr[i] <= arr[j]
			? arr[i++]
			: arr[j++];
	}
	while(i <= mid) tmp[k++] = arr[i++];
	while(j < n) tmp[k++] = arr[j++];
	for (i = 0; i < n; i++)
		arr[i] = tmp[i];
	free(tmp);
}
*/
void merge(int arr[], int tmp[],
           int left, int mid, int right)
{
	/* `mid` belongs to right part. */

	int rt_start, i, n;
	rt_start = mid; /* right part start index */
	i = left; /* tmp array start index */
	n = right - left + 1; /* number of elements */

	while(left < mid && rt_start <= right) {
		tmp[i++] = arr[left] <= arr[rt_start]
			? arr[left++]
			: arr[rt_start++];
	}
	while(left < mid) tmp[i++] = arr[left++];
	while(rt_start <= right) tmp[i++] = arr[rt_start++];

	/* copy to arr */
	for (i = 0; i < n; i++)
		arr[i] = tmp[i];
}

void msort(int arr[], int tmp[],
           int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		msort(arr, tmp, left, mid); /* 先左 */
		msort(arr, tmp, mid + 1, right); /* 后右 */
		merge(arr, tmp, left, mid, right); /* 左右合并 */
	}
}

void merge_sort(int arr[], int n)
{

	int *tmp = malloc(n * sizeof(int));
	if (tmp != NULL) {
		msort(arr, tmp, 0, n - 1);
		free(tmp);
	} else {
		printf("No space for tmp\n");
	}
}

/* 测试 */
int main(void)
{
	// int arr[] = { 1, 2, 5, 7, 3, 4, 6 }; /* 两段已有序 */
	int arr[] = { 3, 1, 4, 2, 5, 7, 6 };
	// merge(arr, 7);
	merge_sort(arr, 7);
	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	return 0;
}
