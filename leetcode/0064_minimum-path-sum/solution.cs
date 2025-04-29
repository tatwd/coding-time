public class Solution {
    public int MinPathSum(int[][] grid) {
        // also use grid as `dp` but it'l change grid values
        var dp = new int[grid.Length, grid[0].Length];

        dp[0, 0] = grid[0][0];

        // set first column path sum
        for (var i = 1; i < grid.Length; i++)
            dp[i, 0] = dp[i - 1, 0] + grid[i][0];

        // set first row path sum
        for (var i = 1; i < grid[0].Length; i++)
            dp[0, i] = dp[0, i - 1] + grid[0][i];

        for (var i = 1; i < grid.Length; i++)
        {
            for (var j = 1; j < grid[i].Length; j++)
            {
                dp[i, j] = Math.Min(dp[i - 1, j], dp[i, j - 1]) + grid[i][j];
            }
        }

        return dp[grid.Length - 1, grid[0].Length - 1];
    }
}
