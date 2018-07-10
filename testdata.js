var { clone } = require('./utils.js');
var _define = Object.defineProperty;
var _keys = Object.keys;

var data = {
  find_in_array_cases: [
    { val: [[1, 2, 3], [4, 5, 6], [7, 8, 9]], exp: true },
    { val: [[1, 2, 3], [4, 8, 6], [7, 8, 9]], exp: false }
  ],
  replace_space_cases: [
    { val: 'hello world', exp: 'hello%20world' },
    { val: 'hello  world', exp: 'hello%20%20world' },
    { val: 'hello world ', exp: 'hello%20world%20' },
    { val: ' hello world', exp: '%20hello%20world' }
  ],
  sorting_cases: [
    {
      val: [34, 8, 64, 51, 32, 21],
      exp: [8, 21, 32, 34, 51, 64]
    },
    {
      val: [34, 8, 64, 21, 32, 21],
      exp: [8, 21, 21, 32, 34, 64]
    }
  ],
  number_format_cases: [
    { val: 123, exp: '123' },
    { val: 1234, exp: '1,234' },
    { val: 123.4542, exp: '123.4542' },
    { val: 1234.5642, exp: '1,234.5642' },
    { val: 123456.78, exp: '123,456.78' },
    { val: 12345678.9, exp: '12,345,678.9' }
  ]
};

var outdata = {};

_keys(data).forEach(key => {
  _define(outdata, key, {
    get: () => clone(data[key]),
    set: value => {
      outdata[key] = value;
    },
    enumerable: true,
    configurable: true
  });
});

module.exports = outdata;
