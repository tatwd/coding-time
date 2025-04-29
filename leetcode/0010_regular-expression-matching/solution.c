#include <stdio.h>

int isMatch(char *s, char *p)
{
    int isMatched = 0;
    /* TODO
    for (int i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] == p[j]) {
            isMatched = 1;
            j++;
            if (p[j] == '\0')
                return 0;
        } else {
            if (p[j] == '.') {
                isMatched = 1;
            } else if (p[j] == '*') {
                if (isMatched)
                    isMatched = p[j-1] != s[i];
            } else {
                isMatched = 0;
            }
        }
    }
    */
    return isMatched;
}

/* 测试 */
int main(void)
{
    char *data[5][2] = {
        {"aa", "a"},
        {"a", "a*"},
        {"ab", ".*"},
        {"aab", "c*a*b"},
        {"mississippi", "mis*is*p*."}
    };
    for (int i = 0; i < 5; i++) {
        int res = isMatch(data[i][0], data[i][1]);
        printf("%d\n", res);
    }
    return 0;
}
