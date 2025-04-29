/**
 * @param {number[]} distance
 * @param {number} start
 * @param {number} destination
 * @return {number}
 */
var distanceBetweenBusStops = function (distance, start, destination) {
  if (start === destination) {
    return 0;
  }

  var d1 = 0;
  var d2 = 0;

  var left = Math.min(start, destination);
  var right = Math.max(start, destination);

  for (var i = 0, n = distance.length; i < n; ++i) {
    if (i < left || i >= right) {
      d2 += distance[i];
    } else {
      d1 += distance[i];
    }
  }

  return Math.min(d1, d2);
};

var testdata = [
  { distance: [1, 2, 3, 4], start: 0, destination: 1 },
  { distance: [1, 2, 3, 4], start: 0, destination: 2 },
  { distance: [1, 2, 3, 4], start: 0, destination: 3 },
  { distance: [3, 6, 7, 2, 9, 10, 7, 16, 11], start: 6, destination: 2 },
];
testdata.forEach((i) => {
  console.log(distanceBetweenBusStops(i.distance, i.start, i.destination));
});
