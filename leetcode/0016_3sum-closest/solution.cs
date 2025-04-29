public class Solution
{
    public int ThreeSumClosest(int[] nums, int target)
    {
        var ans = 100000;

        // sort nums
        Array.Sort(nums);

        for (var i = 0; i < nums.Length; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            var j = i + 1;
            var k = nums.Length - 1;

            while (j < k)
            {
                var sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return sum;

                if (Math.Abs(sum - target) < Math.Abs(ans - target))
                    ans = sum;

                if (sum > target)
                {
                    var k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k0 + 1]) // 跳过重复
                        k0--;
                    k = k0;
                }
                else
                {
                    var j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j0 - 1]) // 跳过重复
                        j0++;
                    j = j0;
                }
            }
        }

        return ans;
    }
}
