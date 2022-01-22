namespace tree;

public static class TreeUtil
{
	public static Node? BuildTree(int[] arr, int left , int right)
	{
		if (left > right) return null;

		int mid = (left + right) / 2;

		Node root = new Node{Val = arr[mid]};
		root.Left = BuildTree(arr, left, mid - 1);
		root.Right = BuildTree(arr, mid + 1, right);

		return root;
	}
}

public class Node
{
	public int Val { get; set; }
	public Node? Left { get; set; }
	public Node? Right { get; set; }
}
