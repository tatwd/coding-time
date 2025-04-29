/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
  if (numRows === 1 || s.length < numRows) return s;

  // Solution 1
  // var result = '';
  // var n = (numRows - 1) * 2;
  // for (var i = 0; i < numRows; ++i) {
  //   var d = i * 2;
  //   for (var j = i; j < s.length; j += d) {
  //     result += s[j];
  //     d = n - d || n;
  //   }
  // }
  // return result;

  // Solution 2
  var result = [];
  var row = 0;
  var goDown = false;
  for (var c of s) {
    result[row] = (result[row] || '') + c;
    if (row == 0 || row == numRows - 1) goDown = !goDown;
    row += goDown ? 1 : -1;
  }
  return result.join('');
};

var data = [
  { s: 'AB', numRows: 1 },
  { s: 'ABC', numRows: 4 },
  { s: 'PAYPALISHIRING', numRows: 3 },
  { s: 'PAYPALISHIRING', numRows: 4 }
];
for (var i of data) {
  var result = convert(i.s, i.numRows);
  console.log(result);
}
// Output:
// AB
// ABC
// PAHNAPLSIIGYIR
// PINALSIGYAHRPI
