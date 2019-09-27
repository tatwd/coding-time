function set_cookie(obj, days, domain, path) {
  var expires, k;
  var nowDate = new Date();
  nowDate.setTime(nowDate.getTime() + days * 24 * 60 * 60 * 1000);
  expires = '; expires=' + nowDate.toGMTString();
  for (k in obj) {
    document.cookie = `${k}=${obj[k]}${expires}; domain=${domain}; path=${path}`;
  }
}

function get_cookie(name) {
  var i, cookie;
  var n = name + '=';
  var cookies = document.cookie.split(';');
  for (i = 0; i < cookies.length; i++) {
    cookie = cookies[i].trim();
    if (cookie.indexOf(n) === 0) {
      return cookie.substring(n.length, cookie.length).replace(/\"/g, '');
    }
  }
  return null;
}
