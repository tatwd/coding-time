function shell_sort(arr) {
  var i, j, current, length, count;
  var increment;

  length = arr.length;
  count = 0;
  for (
    increment = Math.floor(length / 2);
    increment > 0;
    increment = Math.floor(increment / 2)
  )
    for (i = increment; i < length; i++) {
      current = arr[i];
      for (
        j = i;
        j >= increment && arr[j - increment] > current;
        j -= increment
      ) {
        arr[j] = arr[j - increment];
        count++;
      }
      arr[j] = current;
    }
  return count;
}

module.exports = shell_sort;
