/**
 * 在二维数组中查找一个数
 *
 * 该数组从左至右递增，从上至下递增
 */
int find(int arr[][3], int row_length, int col_length, int target) {
    int row, col;

    /* 从左下角开始搜索 */
    row = row_length - 1;
    col = 0;
    while (row >= 0 && col < col_length) {
        if (target < arr[row][col])
            row--;
        else if (target > arr[row][col])
            col++;
        else
            return 1;
    }
    return 0;
}
