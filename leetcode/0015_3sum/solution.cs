public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        var ans = new List<IList<int>>();

        // sort nums
        Array.Sort(nums); // in-place 不稳定的排序

        for (var i = 0; i < nums.Length; i++) {

            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            var a = nums[i];
            var target = -a; // need `b + c` equals target

            var k = nums.Length - 1;

            for (var j = i + 1; j < nums.Length; j++) {

                // 第二重循环枚举到的元素不小于当前第一重循环枚举到的元素
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                var b = nums[j];

                for (; k > j; k--) {
                    var c = nums[k];

                    // if (k != nums.Length - 1 && nums[k] == nums[k + 1])
                    //     continue;

                    if (b + c < target)
                        break; // 此时需要去增大 b 值

                    if (b + c == target) {
                        ans.Add(new List<int>{
                            a, b, c
                        });
                        break;
                    }
                }

            }

        }


        return ans;

    }
}
