function insertion_sort(arr, N) {
  var i, j, current;
  for (i = 1; i < N; i++) {
    current = arr[i];
    for (j = i; j > 0 && arr[j - 1] > current; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = current;
  }
}

module.exports = insertion_sort;
