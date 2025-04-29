/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
  var ans = {};
  for (var i = 0, len = strs.length; i < len; i++) {
    // 排序后的字符顺序相同
    var k = strs[i].split('').sort();
    if (ans[k] === undefined) {
      ans[k] = [strs[i]];
    } else {
      ans[k].push(strs[i]);
    }
  }
  return Object.values(ans);
};

// 测试
var input = ['eat', 'tea', 'tan', 'ate', 'nat', 'bat'];
var output = groupAnagrams(input);
console.log(output);
