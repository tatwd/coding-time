#include <stdio.h>

int isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return 0;
    int r = 0;
    while (r < x) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return x == r || x == r/10;
}

/* 测试 */
int main(void)
{
    int nums[] = {121, -121, 1221, 10, 1, 0};
    for (int i = 0; i < 6; i++) {
        int r = isPalindrome(nums[i]);
        printf("%d\n", r);
    }
    return 0;
}
