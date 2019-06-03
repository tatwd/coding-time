#ifndef BSEARCH_H
#define BSEARCH_H

/**
 * 二分查找 (Binary Search)
 *
 * 仅针对有序 (从小到大) 的数组
 *
 */

/* only for int */
int bsearch1(int key, int arr[], int n);

/* use `memcmp` as default compare function */
int bsearch2(void *key, void *base,
			 int n, int element_size);

/* need to provide a compare function */
int bsearch3(void *key, void *base,
			 int n, int element_size,
			 int (*cmpfn)(void *, void *));

/* a example `cmpfn` for int */
int int_cmp(void *ap, void *bp);

/* 在“旋转数组”中二分查找  */
int bsearch4(int key, int arr[], int n);

#endif
