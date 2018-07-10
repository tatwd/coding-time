var { equal } = require('./utils.js');

/**
 *  A simple unit testing method
 * @param {string} msg
 * @param {function} cb
 */
function utest(msg, cb) {
  var success = false;
  var helper = {
    it: function(actual) {
      return {
        eq: function(expect) {
          success = equal(actual, expect);
          !success
            ? console.log(
                `(X) FAILED: ${msg}\nActual: ${actual}\nExpect: ${expect}\n`
              )
            : console.log(`(V) PASSED!`);
        }
      };
    }
  };
  cb(helper);
}

module.exports = utest;
