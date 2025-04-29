#include <stdio.h>
#include <limits.h>

int reverse(int x)
{
#ifndef INT_MAX
    #define INT_MAX (~(1 << 31))
#endif

#ifndef INT_MIN
    #define INT_MIN (1 << 31)
#endif

    int res = 0;
    int r = 0;
    while (x != 0) {
        r = x % 10;
        if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && r > 7))
            return 0;
        if ((res < INT_MIN / 10) || (res == INT_MIN / 10 && r < -8))
            return 0;
        res = res * 10 + r;
        x /= 10;
    }
    return res;
}

// 测试
int main(void)
{
    int nums[] = {
        123, -123, 120,
        1534236469, -1463847182
    };
    for (int i = 0; i < 5; ++i) {
        int res = reverse(nums[i]);
        printf("%d => %d\n", nums[i], res);
    }
    return 0;
}
