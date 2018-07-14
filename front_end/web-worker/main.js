var testdata = { a: 1, b: 2 };

// create a worker
var worker = new Worker('./worker.js');

// post message to worker
worker.postMessage(testdata);

// add hanndle for message event
worker.onmessage = function(evt) {
  console.log(evt);
  var result = document.querySelector('#result');
  result.innerHTML = `${testdata.a} + ${testdata.b} = ${evt.data.result}`;
};

// add handle for error event
worker.onerror = function(evt) {
  console.log(evt);
};
