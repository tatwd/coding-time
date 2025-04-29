/**
 * @param {number[][]} points
 * @param {number} K
 * @return {number[][]}
 */
var kClosest = function(points, K) {
  var res = [],
    dists = [];
  points.forEach((point, index) => {
    var x = point[0],
      y = point[1];
    dists.push([index, x * x + y * y]);
  });
  dists.sort((a, b) => a[1] - b[1]);
  for (var i = 0; i < K; ++i) {
    res.push(points[dists[i][0]]);
  }
  return res;
};

// 测试
var data = [
  { points: [[1, 3], [-2, 2]], K: 1 },
  { points: [[3, 3], [5, -1], [-2, 4]], K: 2 }
];
for (var i of data) {
  var res = kClosest(i.points, i.K);
  console.log(res);
}
