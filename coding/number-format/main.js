function mumber_format(num) {
  // solution 1
  /*var result = [],
    digit_arr,
    dot_index,
    i,
    len,
    added = -1;

  digit_arr = num.toString().split('');
  len = digit_arr.length;
  dot_index = digit_arr.indexOf('.');

  if (dot_index == -1) dot_index = len;

  if (dot_index <= 3) result = num.toString();
  else {
    added = dot_index % 3 || 3;
    for (i = 0; i < len; i++) {
      if (i == added && added < dot_index) {
        result.push(',');
        added += 3;
      }
      result.push(digit_arr[i]);
    }
  }
  return result;
  */

  // solution 2
  /*return num
    .toString()
    .split('.')
    .reduce(function(result, item, index) {
      if (index == 0) {
        var len = item.length;
        if (len <= 3) result.push(item);
        else {
          var r = len % 3;
          result.push(
            item.split('').reduce(function(str, digit, index) {
              if (index == r) {
                r && (str += ',');
                r += 3;
              }
              return (str += digit);
            }, '')
          );
        }
      } else {
        result.push(item);
      }
      return result;
    }, [])
    .join('.');
  */

  // solution 3
  /*return num
    .toString()
    .split('.')
    .reduce((arr, item, index) => {
      item = !index ? Math.round(item).toLocaleString() : item;
      arr.push(item);
      return arr;
    }, [])
    .join('.');
  */

  // solution 4
  return num.toString().replace(/\d+/, str => {
    return str.replace(/(\d)(?=(\d{3})+$)/g, $1 => $1 + ',');
  });
}

module.exports = mumber_format;
