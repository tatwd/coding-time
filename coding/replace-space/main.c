/**
 * 替换空格
 */
void replace_space(char *str, int length) {
    char *tmp = "%20", *p;
    int space, i, dist;

    /* count space */
    for (space = i = 0; i < length; i++)
        if (str[i] == ' ') space++;

    dist = 2 * space;
    p = tmp + 3;
    for (i = length + dist; i>=0; i--){
        if (p == tmp) p = tmp + 3;

        if (str[i - dist] != ' ') {
            str[i] = str[i - dist];
        } else {
            str[i] = *(--p);
            if (p != tmp) dist--;
        }
    }
}
