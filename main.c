#include <stdio.h>
#include <string.h>
#include "utils.h"

/* @file ./coding/find-in-array/main.c */
extern int find(int arr[][3], int row_length, int col_length, int target);

/* @file ./coding/replace-space/main.c */
extern int replace_space(char *str, int length);

/* @file ./sorting/insertion_sort/main.c */
extern void insertion_sort(int arr[], int n);

/* @file ./sorting/shell_sort/main.c */
extern int shell_sort(int arr[], int n);

/* @file ./sorting/heap_sort/main.c */
extern void heap_sort(int arr[], int n);

/* @file ./sorting/selection_sort/main.c */
extern void selection_sort(int arr[], int n);

/* @file ./sorting/bubble_sort/main.c */
extern void bubble_sort(int arr[], int n);

void test_find() {
    int has;
    int arr[][3] = {
        {0, 1, 3},
        {2, 4, 5},
        {6, 7, 8}
    };

    has = find(arr, 3, 3, 1);
    printf(
        "%d\n",
        has
    );
}

void test_replace_space() {
    char str1[] = "hello world";
    replace_space(str1, strlen(str1));
    utest("replace space with \"%20\": 1 space (body)", str1, "hello%20world");


    char str2[] = "hello world ";
    replace_space(str2, strlen(str2));
    utest("replace space with \"%20\": 2 space (body, tail)", str2, "hello%20world%20");

    char str3[] = "hello  world";
    replace_space(str3, strlen(str3));
    utest("replace space with \"%20\": 2 space (in a row)", str3, "hello%20%20world");

    char str4[] = " hello world";
    replace_space(str4, strlen(str4));
    utest("replace space with \"%20\": 2 space (head, body)", str4, "%20hello%20world");

}

void test_insertion_sort() {
    int n = 6;
    int arr[] = { 34, 8, 64, 51, 32, 21 };

    putarrln("%d ", arr, n);
    insertion_sort(arr, n);
    putarrln("%d ", arr, n);
}

void test_shell_sort() {
    int n = 13;
    int arr[] = { 81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15 };

    putarrln("%d ", arr, n);
    int count = shell_sort(arr, n);
    putarrln("%d ", arr, n);
    printf("count=%d\n", count);
}

void test_heap_sort() {
    int n = 7;
    int arr[] = { 31, 41, 59, 26, 53, 58, 97 };

    heap_sort(arr, n);
    putarrln("%d ", arr, n);
}

void test_selection_sort() {
    int n = 6;
    int arr[] = { 34, 8, 64, 51, 32, 21 };

    putarrln("%d ", arr, n);
    selection_sort(arr, n);
    putarrln("%d ", arr, n);
}

void test_bubble_sort() {
    int n = 6;
    int arr[] = { 34, 8, 64, 51, 32, 21 };

    putarrln("%d ", arr, n);
    bubble_sort(arr, n);
    putarrln("%d ", arr, n);
}

int main () {
    /*
    test_find();
    test_insertion_sort();
    test_shell_sort();
    test_heap_sort();
    test_selection_sort();
    test_bubble_sort();
    */
    test_replace_space();
    return 0;
}
