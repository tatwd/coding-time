/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
const twoSum = function(nums, target) {
  let res = [-1, -1];
  let map = {};

  for (let i = 0; i < nums.length; ++i) {
    if (!isNaN(map[target - nums[i]])) {
      res[0] = map[target - nums[i]];
      res[1] = i;
      break;
    }
    map[nums[i]] = i;
  };

  return res;
};

let result = twoSum([2, 7, 11, 15], 9);
console.log(result);
