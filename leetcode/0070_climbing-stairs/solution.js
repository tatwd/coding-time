/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
  // to slow!
  // if (n === 1) return 1;
  // if (n === 2) return 2;
  // return climbStairs(n - 1) + climbStairs(n - 2);

  // var steps = [0];
  // steps[1] = 1;
  // steps[2] = 2;
  // for (var i = 3; i <= n; ++i) {
  //   steps[i] = steps[i - 1] + steps[i - 2];
  // }
  // return steps[n];

  var a1 = 1;
  var a2 = 1;
  for (var i = 2; i <= n; i++) {
    [a1, a2] = [a2, a1 + a2];
  }
  return a2;
};
