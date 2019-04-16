#include <stdio.h>
#include <stdlib.h>

/* 合并两段有序的数组 */
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

void merge_sort(int arr[], int n)
{
	/* TODO */
}

/* 测试 */
int main(void)
{
	int arr[] = { 1, 2, 5, 7, 3, 4, 6 }; /* 两段已有序 */
	merge(arr, 7);
	for (int i = 0; i < 7; i++)
		printf("%d ", arr[i]);
	return 0;
}
