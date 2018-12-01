function selection_sort(arr) {
  var count = 0;
  for (var i = 0, len = arr.length; i < len - 1; ++i) {
    var min = i;
    for (var j = i + 1; j < len; ++j) {
      count++;
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (i != min) {
      [arr[i], arr[min]] = [arr[min], arr[i]];
    }
  }
  console.log(count);
  return arr;
}

// var arr = [5, 4, 1, 3, 2, 5, 6, 9];
// selection_sort(arr);
// console.log(arr);
