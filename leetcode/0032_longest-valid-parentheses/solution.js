/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
  var buf = [],
    count = 0,
    len = s.length;
  for (var i = 0; i < len; i++) {
    if (buf.length === 0) {
      buf.push(i);
    } else {
      var idx = buf.pop();
      if (s[idx] === '(' && s[i] === ')') {
      } else {
        buf.push(idx, i);
      }
    }
  }
  if (buf.length === len) return 0;
  if (buf.length === 0) return len;
  var low = 0,
    high = len,
    i = 1;
  count = buf[0] - low;
  for (i = 1; i < buf.length; i++) {
    count = Math.max(count, buf[i] - buf[i - 1] - 1);
  }
  return Math.max(count, high - buf[i - 1] - 1);
};

var data = [
  { s: '(', result: 0 },
  { s: '(()', result: 2 },
  { s: '()()', result: 4 },
  { s: ')((()))(', result: 6 }
];
for (var i of data) {
  var result = longestValidParentheses(i.s);
  console.log(result, result === i.result);
}
