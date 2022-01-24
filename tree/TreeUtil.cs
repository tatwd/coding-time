namespace tree;

public static class TreeUtil
{

	/// <summary>
	/// 众字型树构建
	/// </summary>
	public static Node BuildTreeLikeA(int n)
	{
		var root = new Node(1);
		var p = root;
		var q = root;


		// 构建最上面的第 1 个人字
		for (var i = 0; i < n; i++)
		{
			p = AppendChild(p, 1, true);
			q = AppendChild(q, 1, false);
		}

		var pp = p; // 让 pp 去迭代构建右结点
		var qq = q; // 让 qq 去迭代构建左结点

		// 构建底部 2 个人字
		for (var i = 0; i < n; i++)
		{
			p = AppendChild(p, 1, true);
			pp = AppendChild(pp, 1, false);

			q = AppendChild(q, 1, false);
			qq = AppendChild(qq, 1, true);
		}

		return root;
	}

	private static Node AppendChild(Node node, int val, bool toLeft)
	{
		var child = new Node(val);
		return toLeft ? node.Left = child : node.Right = child;
	}

	/// <summary>
	/// build a binary tree from an array
	/// </summary>
	public static Node BuildTreeFromMiddle(int[] arr, int left , int right)
	{
		if (left > right) return null;

		int mid = (left + right) / 2;

		Node root = new Node(arr[mid]);
		root.Left = BuildTreeFromMiddle(arr, left, mid - 1);
		root.Right = BuildTreeFromMiddle(arr, mid + 1, right);

		return root;
	}
}

