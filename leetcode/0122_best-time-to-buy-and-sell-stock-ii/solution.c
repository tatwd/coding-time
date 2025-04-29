#include <stdio.h>

int maxProfit(int *prices, int pricesSize)
{
    /* Solution 1 */
    /*
    int sum = 0, last = 0;
    for (int i = 0, j = 1; j < pricesSize; j++) {
        int cur = prices[j] - prices[i];
        if (cur > last) {
            last = cur;
        } else {
            i = j;
            sum += last;
            last = 0;
        }
    }
    return sum + last;
    */

   /* Solution 2 */
   int sum = 0;
   for (int min = 0, i = 1; i < pricesSize; i++, min++) {
        if (prices[i] > prices[min]) {
            sum += prices[i] - prices[min];
        }
   }
   return sum;
}

/* 测试 */
int main(void)
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int res = maxProfit(prices, 6);
    printf("%d\n", res);
    return 0;
}
