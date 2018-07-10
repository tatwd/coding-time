var { clone } = require('./utils.js');
var _define = Object.defineProperty;
var _keys = Object.keys;

var data = {
  array_cases: [
    { val: [0, 0, 1, 0, 0], exp: [0, 0, 0, 0, 1] },
    { val: [34, 8, 64, 51, 32, 21], exp: [8, 21, 32, 34, 51, 64] }
  ]
};

var outdata = {};

_keys(data).forEach(key => {
  _define(outdata, key, {
    get() {
      return clone(data[key]);
    }
    // set() {},
    // enumerable: true,
    // configurable: true
  });
});

module.exports = outdata;
