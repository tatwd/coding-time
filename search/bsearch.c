#include <stdio.h>
#include <string.h>

#include "bsearch.h"

int bsearch1(int key, int arr[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;

	while (low < high && arr[mid] != key) {
		if (arr[mid] > key) high = mid - 1;
		else low = mid + 1;
		mid = (low + high) /2;
	}
	return key == arr[mid] ? mid : -1;
}

int bsearch2(void *key, void *base,
			 int n, int element_size)
{
	int low, mid, high, result;
	void *ptr;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;

	ptr = (char *)base + mid * element_size;
	result = memcmp(ptr, key, element_size);

	while (low < high && result != 0) {
		if (result > 0) high = mid - 1;
		else low = mid + 1;
		mid = (low + high) /2;
		ptr = (char *)base + mid * element_size;
		result = memcmp(ptr, key, element_size);
	}
	return result == 0 ? mid : -1;
}

int bsearch3(void *key, void *base,
			 int n, int element_size,
			 int (*cmpfn)(void *, void *))
{
	int low, mid, high, result;
	void *ptr;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;

	ptr = (char *)base + mid * element_size;
	result = cmpfn(ptr, key);

	while (low < high && result != 0) {
		if (result > 0) high = mid - 1;
		else low = mid + 1;
		mid = (low + high) /2;
		ptr = (char *)base + mid * element_size;
		result = cmpfn(ptr, key);
	}
	return result == 0 ? mid : -1;
}

int int_cmp(void *ap, void *bp)
{
	int *p1 = ap;
	int *p2 = bp;
	return *p1 -*p2;
}

/*
 * 在“旋转数组”中的二分查找
 * 
 *   [ 3 4 5 6 0 1 2 ] 0 是旋转值
 * 
 * arr: 成员有序且分段，无重复值
 */
int bsearch4(int key, int arr[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	mid = (low + high) >> 1;

	while (low < high && arr[mid] != key) {
		if (arr[low] < arr[mid]) {
			if (key < arr[mid] && key >= arr[low]) 
				high = mid - 1;
			else low = mid + 1;
		} else {
			/*if (key > arr[mid] && key <= arr[high]) 
				low = mid + 1;
			else high = mid - 1;*/
			if (key < arr[mid])
				high = mid - 1;
			else low = mid + 1;
		}
		mid = (low + high) >> 1;

	}
	return key == arr[mid] ? mid : -1;
}
