#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    int* res = malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; ++i) {
        int x = target - nums[i];
        for (int j = i+1; j < numsSize; ++j) {
            if (x == nums[j]) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    res[0] = -1;
    res[1] = -1;
    return res;
}

/* 测试 */
int main()
{
    int nums[] = {2, 7, 11, 15};
    int* res = twoSum(nums, 4, 9);
    printf("[%d, %d]\n", res[0], res[1]);
    free(res);
    return 0;
}
