#include <stdio.h>

/*
剑指 Offer - 4.不修改数组找出中重复的数字

描述:
	在一个长度为 n + 1 的数组里的所有数字都在 1 到 n 的范围内。
	数组中某些数字是重复的，但不知道有几个数字是重复的，也不知道每个数字重复几次。
	请不修改数组元素找出数组中任意一个重复的数字。

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

	int start, mid, end, count;
	start = 1;
	end = length - 1;
	while (start <= end) {
		mid = (start + end) >> 1;
		count = count_range(numbers, length, start, mid);
		if (start == end) {
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (mid - start + 1))
			end = mid;
		else
			start = mid + 1;
	}
	return 0;
}

/* 计算 start ~ end 范围内的数字在数组 numbers 中出现的次数 */
int count_range(int numbers[], int length, int start, int end)
{
	if (numbers == NULL)
		return 0;
	int count = 0;
	for (int i = 0; i < length; ++i)
		if (numbers[i] >= start && numbers[i] <= end)
				count++;
	return count;
}

/* test */
int main(void)
{
	int nums[6] = {2, 3, 1, 4, 2, 5};
	int dup = -1;
	int ok = duplicate(nums, 6, &dup);
	printf("%d %d\n", ok, dup);
	return 0;
}
