class Solution {
  public void ShellSort (int[] arr) {
    int h = 0;
    while (h < arr.Length / 3)
      h = 3 * h + 1; // Knuth 方法

    for (int gap = h; gap > 0; gap /= 2) {
      for (int i = gap; i < arr.Length; i++) {
        int j = i;
        for (; j > 0 && arr[j - gap] > arr[i]; j -= gap) {
          arr[j] = arr[j - gap];
        }
        arr[j] = arr[i];
      }
    }
  }
}
