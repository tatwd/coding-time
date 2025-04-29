#include <stdio.h>
#include <limits.h>
#include <assert.h>

double myPow(double x, int n)
{
    assert(n >= INT_MIN && n <= INT_MAX);

    if (x == 0 || n == 1)
        return x;
    if (x == 1 || n == 0)
        return 1;
    if (x == -1 && n == INT_MIN)
        return 1;
    if (n == INT_MIN)
        return 0;

    if (n < 0) {
        x = 1.0 / x;
        n = -n;
    }

    if (n % 2 == 0)
        return myPow(x * x, n / 2);
    else
        return myPow(x * x, n / 2) * x;
}

// 测试
int main(void)
{
    printf("%f\n", myPow(2.00000, 10));
    printf("%f\n", myPow(2.00000, -2));
    printf("%f\n", myPow(2.00000, INT_MIN));
    printf("%f\n", myPow(8.84372, -5));
    printf("%f\n", myPow(8.84891, -1));
    printf("%f\n", myPow(-1, INT_MIN));
    return 0;
}
/*
1024.000000
0.250000
0.000000
0.000018
0.113008
1.000000
*/
