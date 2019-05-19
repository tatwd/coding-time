/*
斐波那契函数：
f(n) = f(n - 1) + f(n - 2)
*/
#include <stdio.h>
#include <time.h>

/* 递归版 （效率底）*/
long fib1(int n)
{
	if (n <= 1)
		return 1;
	else
		return fib1(n - 1) + fib1(n - 2);
}

/* 迭代版 O(N) */
long fib2(int n)
{
	if (n <= 1)
		return 1;

	long result, a, b;
	a = b = 1;

	for (int i = 2; i <= n; i++) {
		result = a + b;
		a = b;
		b = result;
	}
	return result;
}

/* 测试 */
int main(void)
{
	clock_t start, end;
	int result;

	start =  clock();
	result = fib1(30);
	end =  clock();
	printf("[fib1] result: %d elapsed: %.3fms\n", result,
		1000.0 * (end - start) / CLOCKS_PER_SEC);

	start =  clock();
	result = fib2(30);
	end =  clock();
	printf("[fib2] result: %d elapsed: %.3fms\n", result,
		1000.0 * (end - start) / CLOCKS_PER_SEC);

	return 0;
}
