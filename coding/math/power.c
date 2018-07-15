#include <stdio.h>

/*
 * 高效取幂运算
 * 运算时间 O(log N)
 */
long int
power(long int base, unsigned int exponent) {
    if (base == 1 || exponent == 1)
        return base;
    if (exponent == 0)
        return 1;
    if (base % 2 == 0)
        return power(base * base, exponent / 2);
    else
        return power(base * base, exponent / 2) * base;
}

void test_power() {
    printf("3 ^ 3 = %d\n", power(3, 3));
}
