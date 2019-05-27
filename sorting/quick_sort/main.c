#include <stdio.h>

/* 快速排序 */
void quick_sort(int arr[], int n)
{
	if (arr == NULL || n < 1)
		return;
	void subsort(int arr[], int start, int end);
	subsort(arr, 0, n - 1);
}

void subsort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int key;
	int i, j;

	key = arr[start];
	i = start;
	j = end;

	while(i < j) {
		/* 找出比 key 小的数 */
		while(arr[j] >= key && i < j)
			j--;
		arr[i] = arr[j];

		/* 找出比 key 大的数 */
		while(arr[i] <= key && i < j)
			i++;
		arr[j] = arr[i];
	}

	arr[i] = key;
	subsort(arr, start, i - 1);
	subsort(arr, i + 1, end);
}

/* 测试 */
int main(void)
{
	int arr[] = { 7, 1, 3, 9, 2, 6, 5 };
	quick_sort(arr, 7);
	for (int i = 0, len = sizeof(arr) / sizeof(int); i < len; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
