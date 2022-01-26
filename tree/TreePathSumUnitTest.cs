using Xunit;

namespace tree;

public class TreePathSumUnitTest
{
	[Theory]
	[InlineData(2)]
	[InlineData(20000)]
	public void GetPathSumFromBottomByStack_Ok(int n)
	{
		var root = TreeUtil.BuildTreeLikeA(n);
		Assert.NotNull(root);
		Assert.Equal(1, root.Val);

		var sums = TreePathSum.GetPathSumFromBottomByStack(root);
		var onePathSum = 2 * n + 1;
		Assert.Equal(4, sums.Count);
		Assert.Equal(onePathSum, sums[0]);
	}

	[Theory]
	[InlineData(2)]
	[InlineData(20000)]
	public void GetPathSumFromTopByStack_Ok(int n)
	{
		var root = TreeUtil.BuildTreeLikeA(n);
		Assert.NotNull(root);
		Assert.Equal(1, root.Val);

		var sums = TreePathSum.GetPathSumFromTopByStack(root);
		var onePathSum = 2 * n + 1;
		Assert.Equal(4, sums.Count);
		Assert.Equal(onePathSum, sums[0]);
	}
}
