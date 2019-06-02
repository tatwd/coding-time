namespace Algorithm
{
	partial class Sorting
	{
		// 快速排序
		public static void QuickSort(int[] arr)
		{
			if (arr == null || arr.Length == 0)
				return;
			_subsort(arr, 0, arr.Length - 1);
		}

		private static void _subsort(int[] arr, int start, int end)
		{
			if (start >= end)
				return;

			int current;
			int first, last;

			current = arr[start];
			first = start;
			last = end;

			while (first < last)
			{
				while (first < last && arr[last] >= current)
					last--;
				arr[first] = arr[last];

				while (first < last && arr[first] <= current)
					first++;
				arr[last] = arr[first];
			}
			arr[first] = current;

			_subsort(arr, start, first - 1);
			_subsort(arr, first + 1, end);
		}
	}

	/* 测试 */
	class Program
	{
		static void Main(string[] args)
		{
			int[] arr = { 7, 1, 3, 9, 2, 6, 5 };
			Sorting.QuickSort(arr);
			foreach (var item in arr)
				System.Console.WriteLine(item);
		}
	}
}
