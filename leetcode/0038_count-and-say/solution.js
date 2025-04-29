/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
  if (n === 1) return '1';
  var ans = '';
  var cur = countAndSay(--n);
  var count = 0,
    buf = [];
  for (var i = 0, len = cur.length; i < len; i++) {
    if (buf.length === 0) {
      buf[0] = cur[i];
      count++;
    } else if (buf[0] === cur[i]) {
      count++;
    } else {
      ans += `${count}${buf[0]}`;
      count = 1;
      buf[0] = cur[i];
    }
  }
  if (count !== 0) ans += `${count}${buf[0]}`;
  return ans;
};

// 测试
var data = [
  { n: 1, result: '1' },
  { n: 2, result: '11' },
  { n: 3, result: '21' },
  { n: 4, result: '1211' },
  { n: 5, result: '111221' }
];
for (var i of data) {
  var result = countAndSay(i.n);
  console.log(result, result === i.result);
}
