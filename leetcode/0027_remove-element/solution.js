/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
  var hit = 0;
  for (var i = 0, len = nums.length; i < len; i++) {
    if (nums[i] !== val) {
      nums[hit] = nums[i];
      hit++;
    }
  }
  return hit;
};

// 测试
var data = [
  { nums: [1], val: 1 },
  { nums: [1, 2], val: 3 },
  { nums: [3, 2, 2, 3], val: 3 },
  { nums: [0, 1, 2, 2, 3, 0, 4, 2], val: 2 }
];
for (var i of data) {
  var len = removeElement(i.nums, i.val);
  console.log(len, i.nums.slice(0, len));
}
