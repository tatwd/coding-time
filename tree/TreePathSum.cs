using System.Linq;
using System.Collections.Generic;

namespace tree;

public static class TreePathSum
{
	/// <summary>
	/// 利用栈 自底向上计算所有路径和
	/// </summary>
	public static IList<int> GetPathSumFromBottomByStack(Node root)
	{
		var stack = new Stack<Frame>();
		var primer = new Frame(root);
		stack.Push(primer);

		while (true)
		{
			var top = stack.Peek();

			if (top.Node == null)
			{
				stack.Pop();
				stack.Peek().Count++;
				continue;
			}

			// 该左结点进栈
			if (top.Count == 0)
			{
				stack.Push(new Frame(top.Node.Left));
				continue;
			}

			// 该右结点进栈
			if (top.Count == 1)
			{
				stack.Push(new Frame(top.Node.Right));
				continue;
			}

			var popped = stack.Pop();

			// 是叶子结点
			if (!popped.Sums.Any())
				popped.Sums.Add(popped.Node.Val);

			if (!stack.Any()) break;

			top = stack.Peek();

			// 将子结点的和加到父结点的和中
			foreach (var sum in popped.Sums)
				top.Sums.Add(sum + top.Node.Val);
			top.Count++;
		}

		return primer.Sums;

	}

	private class Frame
	{
		public Node Node { get; set; }
		public IList<int> Sums { get; set; }

		/// <summary>
		/// 记录已处理完的左右结点
		/// 0： 要处理左结点
		/// 1： 要处理右结点
		/// 2: 左右结点都处理完了 该 copy 底下的和了
		/// </summary>
		public int Count { get; set; }

		public Frame(Node node)
		{
			Node = node;
			Sums = new List<int>(0);
		}
	}

	/// <summary>
	/// 利用栈 自顶向下计算所有路径和
	/// </summary>
	public static IList<int> GetPathSumFromTopByStack(Node root)
	{
		var sums = new List<int>();
		var stack = new Stack<Frame2>();
		var primer = new Frame2(root);
		primer.Sum = root.Val;
		stack.Push(primer);

		while (true)
		{
			var top = stack.Peek();

			if (top.Node == null)
			{
				stack.Pop();
				stack.Peek().Count++;
				continue;
			}

			// 该左结点进栈
			if (top.Count == 0)
			{
				var leftFrame = new Frame2(top.Node.Left);
				if (leftFrame.Node != null)
					leftFrame.Sum = top.Sum + leftFrame.Node.Val;
				stack.Push(leftFrame);
				continue;
			}

			// 该右结点进栈
			if (top.Count == 1)
			{
				var rightFrame = new Frame2(top.Node.Right);
				if (rightFrame.Node != null)
					rightFrame.Sum = top.Sum + rightFrame.Node.Val;
				stack.Push(rightFrame);
				continue;
			}

			var popped = stack.Pop();

			// 叶子结点
			if (popped.Node.Left == null && popped.Node.Right == null)
				sums.Add(popped.Sum);

			if (!stack.Any()) break;
			stack.Peek().Count++;
		}

		return sums;

	}

	private class Frame2
	{
		public Node Node { get; set; }
		public int Sum { get; set; }

		/// <summary>
		/// 记录已处理完的左右结点
		/// 0： 要处理左结点
		/// 1： 要处理右结点
		/// 2: 左右结点都处理完了 该 copy 底下的和了
		/// </summary>
		public int Count { get; set; }

		public Frame2(Node node)
		{
			Node = node;
		}
	}


}
