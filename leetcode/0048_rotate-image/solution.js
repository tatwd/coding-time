/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
  // Solution 1
  // var n = matrix.length;
  // for (var i = 0; i < n; i++) {
  //   for (var j = i; j < n; j++) {
  //     [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
  //   }
  // }
  // for (var i = 0; i < n; i++) {
  //   for (var j = 0, k = n-1; j < k; j++, k--) {
  //     [matrix[i][j], matrix[i][k]] = [matrix[i][k], matrix[i][j]];
  //   }
  // }

  // Solution 2
  var n = matrix.length;
  for (var i = 0; i < n - i; i++) {
    for (var j = i; j < n - i - 1; j++) {
      // TODO
    }
  }
};

// 测试
var data = [
  {
    matrix: [
      [1, 2, 3],
      [4, 5, 6],
      [7, 8, 9]
    ],
    result: [
      [7, 4, 1],
      [8, 5, 2],
      [9, 6, 3]
    ]
  },
  {
    matrix: [
      [5, 1, 9, 11],
      [2, 4, 8, 10],
      [13, 3, 6, 7],
      [15, 14, 12, 16]
    ],
    result: [
      [15, 13, 2, 5],
      [14, 3, 4, 1],
      [12, 6, 8, 9],
      [16, 7, 10, 11]
    ]
  }
];
for (var i of data) {
  var result = rotate(i.matrix);
  console.log(i.matrix);
}
