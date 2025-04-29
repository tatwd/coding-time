#include <stdio.h>

int removeElement(int *nums, int numsSize, int val)
{
    int hit = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[hit] = nums[i];
            hit++;
        }
    }
    return hit;
}

/* 测试 */
int main()
{
    int nums[] = { 3, 2, 2, 3 };
    int len = removeElement(nums, 4, 3);
    printf("%d [ ", len);
    for (int i = 0; i < len; i++)
        printf("%d ", nums[i]);
    printf("]\n");
    return 0;
}
