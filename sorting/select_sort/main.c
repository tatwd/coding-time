#include "../../utils.h"

void select_sort(int arr[], int n) {
  int i, j, min;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[i])
        swap(arr+i, arr+j);
    }
  }
}

int main() {
  int n = 6;
  int arr[] = { 34, 8, 64, 51, 32, 21 };

  putarrln("%d ", arr, n);
  select_sort(arr, n);
  putarrln("%d ", arr, n);

  return 0;
}