function insertion_sort(arr) {
  var i, j, len, current;
  for (i = 1, len = arr.length; i < len; i++) {
    current = arr[i];
    for (j = i; j > 0 && arr[j - 1] > current; j--) {
      arr[j] = arr[j - 1];
    }
    arr[j] = current;
  }
}

module.exports = insertion_sort;
