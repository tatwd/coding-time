## 数组

### `sort(function?:cb)`

[V8](https://github.com/v8/v8) 对该排序的实现是快速排序（Quick Sort）和插入排序（Insetion Sort）相结合，当数组长度小于等于 10 时采用插入排序，否则使用快速排序（[详情](https://github.com/v8/v8/blob/e6bebb3a28dcb9b3fd4db1c506d8c3212ca19e61/src/js/array.js#L645)）。此外该排序是不稳定的排序，可定制回调来避免。
