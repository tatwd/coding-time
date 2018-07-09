var successTotal = 0,
  failedTotal = 0;

function type(obj) {
  return Object.prototype.toString.call(obj).match(/\[object (.*)\]/)[1];
}

function isObject(obj) {
  return type(obj) === 'Object';
}

function isArray(obj) {
  return type(obj) === 'Array';
}

function eqType(obj1, obj2) {
  return type(obj1) === type(obj2);
}

function eqArray(arr1, arr2) {
  var i,
    len1 = arr1.length,
    len2 = arr2.length;

  if (len1 !== len2) return false;
  for (i = 0; i < len1; i++) {
    if (eqType(arr1[i], arr2[i])) {
      if (arr1[i] !== arr2[i]) return false;
    } else {
      return false;
    }
  }
  return true;
}

function utest(msg, cb) {
  var success = false;
  var helper = {
    it: function(actual) {
      return {
        eq: function(expect) {
          console.log('Actual:', actual);
          console.log('Expect:', expect);
          if (isArray(actual)) {
            success = eqArray(actual, expect);
          } else if (isObject(actual)) {
          } else {
            success = actual == expect;
          }
        }
      };
    }
  };

  cb(helper);

  if (success) {
    successTotal++;
    console.log('Successful!\n');
  } else {
    failedTotal++;
    console.warn('Failed:', msg, '\n');
  }
  // console.log(
  //   'Completed ' + successTotal + ' successfully, and ',
  //   failedTotal + ' failed!'
  // );
}

module.exports = utest;
