/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
  var out = [];
  var count = {};

  for (var i of nums1) {
    if (count[i] === undefined) {
      count[i] = 1;
    } else {
      count[i] += 1;
    }
  }

  for (var i of nums2) {
    if (count[i] > 0) {
      out.push(i);
      count[i] -= 1;
    }
  }

  return out;
};

var testdata = [
  { nums1: [1, 2, 2, 1], nums2: [2, 2], result: [2, 2] },
  { nums1: [4, 9, 5], nums2: [9, 4, 9, 8, 4], result: [4, 9] },
];
testdata.forEach((i) => {
  console.log(intersect(i.nums1, i.nums2));
});
