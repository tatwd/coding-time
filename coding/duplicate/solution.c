#include <stdio.h>

/*
剑指 Offer - 3.数组中重复的数字

描述:
	在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。
	数组中某些数字是重复的，但不知道有几个数字是重复的，也不知道每个数字重复几次。
	请找出数组中任意一个重复的数字。

参数:
	numbers: 整数数组
	length: 数组长度
	duplication: (Output) 重复的数字

返回值:
	1 表示输入正常并找到重复数字
	0 表示输入异常或无重复数字
*/
int duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == NULL || length <= 0)
		return 0;
	for (int i = 0; i < length; i++) {
		while(numbers[i] != i){
			int index = numbers[i];
			if (numbers[i] == numbers[index]) {
				*duplication = index;
				return 1;
			}
			numbers[i] = numbers[index];
			numbers[index] = index;
		}
	}
	return 0;
}

/* test */
int main(void)
{
	int nums[6] = {2, 3, 1, 0, 2, 5};
	int dup = -1;
	int ok = duplicate(nums, 6, &dup);
	printf("%d %d", ok, dup);
	return 0;
}
