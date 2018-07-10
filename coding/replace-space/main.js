function replace_space(str) {
  // solution 1
  // return str.replace(/\s/g, fmt);

  // solution 2
  // return str.split(/\s/).join(fmt);

  // solution 3
  var len = str.length;
  var str = str.split('');
  var i,
    space = 0,
    dist;

  for (i = 0; i < len; i++) str[i] === ' ' && space++;

  dist = 2 * space;
  for (i = len - 1; i >= 0; i--) {
    if (str[i] !== ' ') {
      str[i + dist] = str[i];
    } else {
      str[i + dist--] = '0';
      str[i + dist--] = '2';
      str[i + dist] = '%';
    }
  }
  return str.join('');
}

module.exports = replace_space;
