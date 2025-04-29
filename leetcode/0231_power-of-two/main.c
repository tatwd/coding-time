#include <stdio.h>

int isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

/* 测试 */
int main(int argc, char const *argv[])
{
    int nums[] = {-1, 0, 1, 16, 218};
    int result;
    for (int i = 0; i < 5; ++i) {
        result = isPowerOfTwo(nums[i]);
        printf("%s\n", result ? "true" : "false");
    }
    return 0;
}
/*
false
false
true
true
false
*/
