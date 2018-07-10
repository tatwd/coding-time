#ifndef UTILS__H
#define UTILS__H

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define ENDLINE printf("\n")

void putarr(char *str, int *arr, int n) {
    assert(str != NULL);
    for (int *p = arr; p != arr+n; p++)
        printf(str, *p);
}

void putarrln(char *str, int *arr, int n) {
    putarr(str, arr, n);
    printf("\n");
}

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int utest(const char *msg, char *actual, char *expect) {
    assert(actual != NULL && expect != NULL);

    if (strcmp(actual, expect)) {
        printf(
            "ACTUAL: %s\n"
            "EXPECT: %s\n"
            "FAILED: %s\n\n",
            actual, expect, msg
        );
        return 1;
    } else {
        printf("PASSED!\n");
        return 0;
    }
}

#endif
