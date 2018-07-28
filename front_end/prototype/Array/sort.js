var data = null;

// basic usage
data = [4, 2, 3, 5, 1];
data.sort();
data.sort(function(a, b) {
  return b - a; // descending
});

// for multi type data sprt
data = ['aa', 'bb', 'a', 4, 23, 56, 2, 3];
data.sort(function(a, b) {
  if (a === b) return 0;
  if (typeof a === typeof b) {
    return a < b ? -1 : 1;
  }

  // sort by type name
  return typeof a < typeof b ? -1 : 1;
});
// console.log(data);

// sort for a object
data = [
  { first: 'Joe', last: 'Besser' },
  { first: 'Moe', last: 'Howard' },
  { first: 'Joe', last: 'DeRita' },
  { first: 'Shemp', last: 'Howard' },
  { first: 'Larry', last: 'Fine' },
  { first: 'Curly', last: 'Howard' }
];

// sort by name of a object
// return a compare func
var by = function(name) {
  return function(o, p) {
    var a, b;
    if (o && p && typeof o === 'object' && typeof p === 'object') {
      a = o[name];
      b = p[name];
      if (a === b) return 0;
      if (typeof a === typeof b) {
        return a < b ? -1 : 1;
      }
      return typeof a < typeof b ? -1 : 1;
    } else {
      throw {
        name: 'Error',
        message: `Failed to sort the array items by '${name}' field!`
      };
    }
  };
};

data.sort(by('first'));
// console.log(data);

// unstable sort
// data.sort(by('first')).sort(by('last'));
// console.log(data);

// call minor func when items are same
by = function(name, minor) {
  return function(o, p) {
    var a, b;
    if (o && p && typeof o === 'object' && typeof p === 'object') {
      a = o[name];
      b = p[name];
      if (a === b) {
        // sort by minor func
        return typeof minor === 'function' ? minor(o, p) : 0;
      }
      if (typeof a === typeof b) {
        return a < b ? -1 : 1;
      }
      return typeof a < typeof b ? -1 : 1;
    } else {
      throw {
        name: 'Error',
        message: `Failed to sort the array items by '${name}' field!`
      };
    }
  };
};

data.sort(by('last', by('first')));
console.log(data);
