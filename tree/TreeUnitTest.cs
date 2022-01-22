using Xunit;

namespace tree;

public class TreeUnitTest
{
	[Fact]
	public void BuildTree_Ok()
	{
		var arr = new [] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		var root = TreeUtil.BuildTree(arr, 0, arr.Length - 1);
		Assert.NotNull(root);
		Assert.Equal(5, root.Val);
	}
}
