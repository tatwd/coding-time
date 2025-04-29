#include <stdio.h>

int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int i, j;
    for (i = 0, j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}

/* 测试 */
int main(void)
{
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int len = removeDuplicates(nums, 10);
    printf("%d\n", len); /* 5 */
    return 0;
}
