var testdata = require('./testdata.js');
var { utest } = require('./utils.js');

// to test methods

var find = require('./coding/find-in-array/main.js');
var replace_space = require('./coding/replace-space/main.js');
var mumber_fromat = require('./coding/number-format/main.js');
var insertion_sort = require('./sorting/insertion_sort/main.js');
var shell_sort = require('./sorting/shell_sort/main.js');

// start testing

utest('should be found `5` in array!', ({ it }) => {
  testdata.find_in_array_cases.forEach(({ val, exp }) => {
    it(find(val, 5)).eq(exp);
  });
});

utest('should replace space by `%20`', ({ it }) => {
  testdata.replace_space_cases.forEach(({ val, exp }) => {
    it(replace_space(val)).eq(exp);
  });
});

utest('should be return integer', ({ it }) => {
  testdata.number_format_cases.forEach(({ val, exp }) => {
    it(mumber_fromat(val)).eq(exp);
  });
});

utest('should be sorted!', ({ it }) => {
  // testing insertion sort
  testdata.sorting_cases.forEach(({ val, exp }) => {
    insertion_sort(val);
    it(val).eq(exp);
  });

  // testing shell sort
  testdata.sorting_cases.forEach(({ val, exp }) => {
    shell_sort(val);
    it(val).eq(exp);
  });
});

// end testing
