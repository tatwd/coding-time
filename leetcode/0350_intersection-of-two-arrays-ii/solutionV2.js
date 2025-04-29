/**
 * 当 nums1 和 nums2 有序
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
  var out = [];
  var i = 0,
    j = 0,
    len1 = nums1.length,
    len2 = nums2.length;

  // nums1.sort((a, b) => a - b);
  // nums2.sort((a, b) => a - b);

  while (i < len1 && j < len2) {
    if (nums1[i] === nums2[j]) {
      out.push(nums1[i]);
      i++;
      j++;
    } else if (nums1[i] > nums2[j]) {
      j++;
    } else {
      i++;
    }
  }

  return out;
};

var testdata = [
  { nums1: [1, 1, 2, 2], nums2: [2, 2], result: [2, 2] },
  { nums1: [4, 5, 9], nums2: [4, 4, 8, 9, 9], result: [4, 9] },
];
testdata.forEach((i) => {
  console.log(intersect(i.nums1, i.nums2));
});
