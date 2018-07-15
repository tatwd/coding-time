extern void swap(int *a, int *b);

/**
 * 求最大共因数（GCD）
 * 运行时间 O(log N)
 */
unsigned int
gcd(unsigned int m, unsigned int n) {
    unsigned int rem; /* 余数 */
    if (m < n) {
        swap(&m, &n);
    }
    while (n > 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}
