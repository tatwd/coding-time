var loading = document.querySelector('#loading');
var apiUri = 'https://api.github.com/users';

var xhr = new XMLHttpRequest() || new ActiveXObject('Microsoft.XMLHTTP');

xhr.onreadystatechange = function() {
  if (xhr.readyState === 4) {
    if (xhr.status === 200) {
      // console.log(xhr);
      document.querySelector('#users').innerHTML = xhr.responseText;
    }
  }
};

xhr.onprogress = function(evt) {
  // console.log(evt.lengthComputable);
  if (evt.lengthComputable) {
    loading.max = evt.total;
    loading.value = (evt.loaded / evt.total) * 100;
  }
};

xhr.onloadend = function(evt) {
  loading.value = evt.loaded;
};

xhr.open('GET', apiUri, true);
xhr.send(null);

// async is false
/*
xhr.open('GET', apiUri + '/2', false);
xhr.send(null);
document.querySelector('#users').innerHTML = xhr.responseText;
*/
