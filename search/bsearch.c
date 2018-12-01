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
