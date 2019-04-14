#include <stdio.h>

/* 和最大子串 */
int max_sum(int arr[], int n)
{
	int result, sum;
	int i;
	result = arr[0];
	sum = arr[0];
	for (i = 1; i < n; i++) {
		if (sum < 0)
			sum = arr[i];
		else
			sum += arr[i];
		if (sum > result)
			result = sum;
	}
	return result;
}

int main(void)
{
	int arr[] = {1, -1, 3, -2, 7, -1};
	int result = max_sum(arr, 6);
	printf("%d\n", result); /* 8 {3, -2, 7} */
	return 0;
}
