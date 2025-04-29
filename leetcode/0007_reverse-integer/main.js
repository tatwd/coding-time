/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
  var i32_max = ~(1 << 31);
  var i32_min = 1 << 31;

  var res = 0;
  var r = 0;
  while (x != 0) {
    r = x % 10;

    // 判断溢出
    // i32_max % 10 = 7
    // i32_min % 10 = -8
    if ((res === i32_max / 10 && r > 7) || res > i32_max / 10) return 0;
    if ((res === i32_min / 10 && r < -8) || res < i32_min / 10) return 0;

    res = res * 10 + r;
    x = (x / 10) ^ 0;
  }
  return res;
};

var data = [
  { x: 123, result: 321 },
  { x: -123, result: -321 },
  { x: 120, result: 21 },
  { x: 1534236469, result: 0 }
];
for (var i of data) {
  var result = reverse(i.x);
  console.log(result === i.result);
}
