var apiUri = 'https://api.github.com/users/tatwd';

var xhr = new XMLHttpRequest() || new ActiveXObject('Microsoft.XMLHTTP');

xhr.onreadystatechange = function() {
  if (xhr.readyState === 4) {
    if (xhr.status === 200) {
      console.log(xhr);
      document.querySelector('#users').innerHTML = xhr.responseText;
    }
  }
};

/*
xhr.onprogress = function(evt) {
  console.log(evt);
};
*/

xhr.open('GET', apiUri, true);
xhr.send(null);
