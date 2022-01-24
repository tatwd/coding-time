using Xunit;

namespace tree;

public class TreeUtilUnitTest
{
	[Fact]
	public void BuildTreeLikeA_Ok()
	{
		var root = TreeUtil.BuildTreeLikeA(2);
		Assert.NotNull(root);
		Assert.Equal(1, root.Val);
	}

	[Fact]
	public void BuildTreeFromMiddle_Ok()
	{
		var arr = new [] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		var root = TreeUtil.BuildTreeFromMiddle(arr, 0, arr.Length - 1);
		Assert.NotNull(root);
		Assert.Equal(5, root.Val);
	}
}
