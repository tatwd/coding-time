#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int myAtoi(char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    char *p = str;
    int res = 0, sign = 1, cur = 0;
    int i32_max_10r = INT_MAX / 10;
    int i32_min_10r = INT_MIN / 10;

    /* 排除空白符 */
    while (isspace(*p))
        p++;

    /* 确定符号 */
    /*
    if (*p == '-' || *p == '+') {
        if (*p == '-') sign = -1;
        p++;
    }
    */
    ((*p == '-' && (sign = -1)) || *p == '+') && (p++);

    for (; *p != '\0' && isdigit(*p); p++) {
        cur = sign * (*p - '0');

        /* 溢出检查 */
        if (sign > 0) {
            if ((res > i32_max_10r) || (res == i32_max_10r && cur > 7))
                return INT_MAX;
        } else {
            if ((res < i32_min_10r) || (res == i32_min_10r && cur < -8))
                return INT_MIN;
        }

        res = res * 10 + cur;
    }
    return res;
}

/* 测试 */
int main(void)
{
    char *strs[] = {
        "",
        "42",
        "+1",
        "   -42",
        "4193 with words",
        "words and 987",
        "-91283472332",
        "2147483649"
    };
    for (int i = 0; i < 8; ++i) {
        int result = myAtoi(strs[i]);
        printf("\"%s\" => %d\n", strs[i], result);
    }
    return 0;
}
