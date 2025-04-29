/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
  // Solution 1
  // var chars = [];
  // var result = 0;
  // for (var i = 0, len = s.length; i < len; ++i) {
  //   var index = chars.indexOf(s[i])
  //   if (index !== -1) {
  //     chars = chars.slice(index + 1);
  //   }
  //   chars.push(s[i]);
  //   result = Math.max(result, chars.length);
  // }
  // return result;

  // Solution 2
  // hit_index = max(current_hit_index, hit_index)
  // result = max(result, index - hit_index)
  var map = {};
  var result = 0;
  var hit = -1;
  for (var i = 0, len = s.length; i < len; ++i) {
    if (map[s[i]] !== undefined) hit = Math.max(map[s[i]], hit);
    result = Math.max(result, i - hit);
    map[s[i]] = i;
  }
  return result;
};

var data = [
  { s: '', result: 0 },
  { s: ' ', result: 1 },
  { s: 'abba', result: 2 },
  { s: 'dvdf', result: 3 },
  { s: 'ckilbkd', result: 5 },
  { s: 'abcabcbb', result: 3 },
  { s: 'bbbbb', result: 1 },
  { s: 'pwwkew', result: 3 }
];
for (var i of data) {
  let result = lengthOfLongestSubstring(i.s);
  console.log(result, result === i.result);
}
