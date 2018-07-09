var utest = require('./utest.js');

/* coding modules */
var find = require('./coding/find-in-array/main.js');
var replace_space = require('./coding/replace-space/main.js');

/* sorting module */
var insertion_sort = require('./sorting/insertion_sort/main.js');
var shell_sort = require('./sorting/shell_sort/main.js');

utest('should be found `5` in array!', ({ it }) => {
  var arr = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
  it(find(arr, 5)).eq(true);
});

utest('should replace space by `%20`', ({ it }) => {
  var str = 'We Are Happy';
  it(replace_space(str, '%20')).eq('We%20Are%20Happy');
});

var example = [34, 8, 64, 51, 32, 21];

utest('should be sorted!', ({ it }) => {
  // var arr = [81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15],
  var arr = example,
    expect = [8, 21, 32, 34, 51, 64];

  // insertion_sort(arr, 6);
  shell_sort(arr);
  it(arr).eq(expect);
});
