/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
  if (num1 == '0' || num2 == '0') return '0';

  var len1 = num1.length,
    len2 = num2.length,
    ans = [];

  for (var i = len1 - 1; i >= 0; --i) {
    var r = 0,
      z = 0;
    var k = ans.length - (len1 - i);
    for (var j = len2 - 1; j >= 0; --j) {
      var cur = num2[j] * num1[i] + z;
      var old = k < 0 || ans[k] === undefined ? 0 : ans[k];
      var v = cur + old;

      r = v % 10; // 取余
      z = (v / 10) ^ 0; // 取整

      if (k >= 0) ans[k] = r;
      else ans.unshift(r);
      k--;
    }
    if (z !== 0) ans.unshift(z);
  }
  return ans.join('');
};

// 测试
var data = [
  { num1: '2', num2: '3', result: '6' },
  { num1: '123', num2: '456', result: '56088' },
  { num1: '123456789', num2: '987654321', result: '121932631112635269' },
  { num1: '9333', num2: '0', result: '0' }
];
for (var i of data) {
  var result = multiply(i.num1, i.num2);
  console.log(result, result === i.result);
}
