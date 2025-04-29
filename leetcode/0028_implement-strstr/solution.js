/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
  // Solution 1
  // var ans = -1,
  //   len1 = haystack.length,
  //   len2 = needle.length;
  // for (var i = 0, j = 0; i < len1 && j < len2; i++) {
  //   if (haystack[i] === needle[j]) {
  //     j++;
  //   } else {
  //     i = i - j;
  //     j = 0;
  //   }
  // }
  // if (j === len2) return i - j;
  // return ans;

  // Solution 2
  // 使用 KMP 算法
  var ans = -1,
    len1 = haystack.length,
    len2 = needle.length;

  var get_k = function(s) {
    var next = [], k = -1;
    for (var i = 0, len = s.length; i < len - 1; i++) {
      // TODO
    }
    return next;
  };
  var next = get_k(needle);

  for (var i = 0, j = 0; i < len1 && j < len2; ) {
    if (j == -1 || haystack[i] === needle[j]) {
      j++;
      i++;
    } else {
      j = next[j];
    }
  }
  if (j === len2) return i - j;
  return ans;
};

var data = [
  { haystack: '', needle: '', result: 0 },
  { haystack: 'hello', needle: 'll', result: 2 },
  { haystack: 'aabaaabaaac', needle: 'aabaaac', result: 4 },
];
for (var i of data) {
  var result = strStr(i.haystack, i.needle);
  console.log(result, result === i.result);
}
