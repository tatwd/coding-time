/**
 * A type checker
 * @param {any} value
 */
function type(value) {
  return Object.prototype.toString.call(value).match(/\[object (.*)\]/)[1];
}

type.isArray = function(arr) {
  return this(arr) === 'Array';
};

type.isObject = function(obj) {
  return this(obj) === 'Object';
};

/**
 * Deep clone for array and object
 * @param {arry object} value
 */
function clone(value) {
  if (type.isObject(value)) return clone.forObject(value);
  else if (type.isArray(value)) return clone.forArray(value);
  else return value;
}

clone.forObject = function(obj) {
  return Object.entries(obj).reduce((result, [key, val]) => {
    result[key] = this(val);
    return result;
  }, {});
};

clone.forArray = function(arr) {
  return arr.reduce((result, item) => {
    result.push(this(item));
    return result;
  }, []);
};

/**
 * Check a equals b or not
 * @param {any} a
 * @param {any} b
 */
function equal(a, b) {
  if (type.isArray(a)) return equal.forArray(a, b);
  else return a === b;
}

equal.forArray = function(a, b) {
  if (a.length !== b.length) return false;
  var item, arr, len;
  arr = a.map((item, i) => [].concat(item, b[i])); /* 按下标合并两个数组 */
  for (item of arr) {
    if (!this(item[0], item[1])) return false;
  }
  return true;
};

equal.forObject = function(a, b) {
  // TODO
};

module.exports = {
  type,
  clone,
  equal
};
