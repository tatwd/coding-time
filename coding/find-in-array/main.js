function find(arr, target) {
  var row_length, col_length, row, col, current;

  row_length = arr.length;
  col_length = arr[0].length;
  row = row_length - 1;
  col = 0;

  while (row >= 0 && col < col_length) {
    current = arr[row][col];
    if (target < current) row--;
    else if (target > current) col++;
    else return true;
  }
  return false;
}

module.exports = find;
