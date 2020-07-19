#include <stdio.h>
/*extern void swap(int *a, int *b);*/

/**
 * 求最大共因数（GCD）
 * 运行时间 O(log N)
 *
 * 欧几里得算法
 */
unsigned int
gcd(unsigned int m, unsigned int n) {
    unsigned int rem; /* 余数 */
    /*if (m < n) {
        swap(&m, &n);
    }*/
    while (n > 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

/* 递归实现 */
unsigned int
gcd2(unsigned int m, unsigned int n) {
    /*if (m < n) swap(&m, &n);*/
    return n == 0 ? m : gcd2(n, m % n);
}

/* 更相减损法（消除mod运算） m n 两数相差较大时 时间复杂度O(N) */
unsigned int
gcd3(unsigned int m, unsigned int n) {
	return m == n ? m : (m > n ? gcd3(m - n, n) : gcd3(n - m, m));
}

/*
 a) m is even, n is even => gcd(m,n)=gcd(m/2,n/2)*2
 b) m is even, n is odd => gcd(m,n)=gcd(m/2,n)
 c) m is odd, n is even => gcd(m,n)=gcd(m,n/2)
 d) m is odd, n is odd => gcd(m,n)={gcd(m-n,n) m>n, 
                                    gcd(n-m,m) m<n}
 */
unsigned int
gcd4(unsigned int m, unsigned int n) {
	if (m == n) return m;
	if (m & 1) { // true is odd
		if (n & 1) return m > n ? gcd(m - n, n) : gcd(n - m, m);
		return gcd(m, n >> 2);
	}
	if (n & 1) return gcd(m >> 2, n);
	return gcd(m >> 2, n >> 2) << 2;
}

/* 测试 */
int main(void) 
{
	unsigned int m = 560;
	unsigned int n = 232;
	unsigned int a = gcd(m, n);
	unsigned int b = gcd2(m, n);
	unsigned int c = gcd3(m, n);
	unsigned int d = gcd4(m, n);
	printf("a:%d b:%d c:%d d:%d\n", a, b, c, d);
	return 0;
}

