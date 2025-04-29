/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
  return n > 0 && (n & (n - 1)) === 0;
};

// 测试
var data = [
  { n: -1, result: false },
  { n: 0, result: false },
  { n: 1, result: true },
  { n: 16, result: true },
  { n: 218, result: false }
];
for (var i of data) {
  var result = isPowerOfTwo(i.n);
  console.log(result == i.result ? 'ok' : 'failed');
}
