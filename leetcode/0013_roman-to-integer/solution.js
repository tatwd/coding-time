/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
  var map = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
  };
  var res = 0;
  for (var i = 0, len = s.length; i < len - 1; i++) {
    if (map[s[i]] < map[s[i + 1]]) res -= map[s[i]];
    else res += map[s[i]];
  }
  res += map[s[i]];
  return res;
};

// 测试
var data = [
  { input: 'III', output: 3 },
  { input: 'IV', output: 4 },
  { input: 'IX', output: 9 },
  { input: 'LVIII', output: 58 },
  { input: 'MCMXCIV', output: 1994 }
];
for (var i of data) {
  var res = romanToInt(i.input);
  console.log(res, res === i.output);
}
