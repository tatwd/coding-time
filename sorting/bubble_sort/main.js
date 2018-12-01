function bubble_sort(arr) {
  for (var i = 0, len = arr.length; i < len - 1; ++i) {
    var swaped = false;
    for (var j = 0; j < len - i - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
        swaped = true;
      }
    }
    if (!swaped) break;
  }
  return arr;
}

// var arr = [5, 4, 1, 3, 2, 5, 6, 9];
// bubble_sort(arr);
// console.log(arr);
