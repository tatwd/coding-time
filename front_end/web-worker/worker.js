// `this` is current worker instance
console.log(this);

// get data from main thread
this.onmessage = function(evt) {
  if (evt.data) {
    var result = evt.data.a + evt.data.b;
    postMessage({ result });
  }
};
