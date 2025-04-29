/**
 * @param {string} date
 * @return {number}
 */
var dayOfYear = function (date) {
  var [year, month, day] = date.split("-").map(Number);
  var isLeap = year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
  var monthDays = [
    31,
    isLeap ? 29 : 28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31,
  ];

  // var nthDay = day;
  // for (var i = 0; i < 12; ++i) {
  //   if (i + 1 >= month) {
  //     break;
  //   }
  //   nthDay += monthDays[i];
  // }
  // return nthDay;
  return (
    Number(month > 1 && monthDays.slice(0, month - 1).reduce((a, b) => a + b)) +
    day
  );
};

var testdata = [
  { date: "2019-01-09", result: 9 },
  { date: "2019-02-10", result: 41 },
  { date: "2003-03-01", result: 60 },
  { date: "2004-03-01", result: 61 },
];
testdata.forEach((i) => {
  var days = dayOfYear(i.date);
  console.assert(
    days === i.result,
    `${i.date} compute dayOfYear fail: ${days} !== ${i.result}`
  );
});
