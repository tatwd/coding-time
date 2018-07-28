const container = document.querySelector('#container');
const btn = document.querySelector('#btn');
const dispatchBtn = document.querySelector('#dispatch-btn');

// only set once
btn.onclick = function() {
  console.log('btn', 1);
};

btn.addEventListener(
  'click',
  function() {
    console.log('btn:', 2);
  },
  true
);

btn.addEventListener(
  'click',
  function() {
    console.log('btn:', 3);
  },
  false
);

btn.addEventListener(
  'click',
  function() {
    console.log('btn:', 4);
  },
  {
    capture: false,
    once: true, // click once
    passive: true // never call preventDefault()
  }
);

container.addEventListener(
  'click',
  function() {
    console.log('container:', 5);
  },
  true // call in captrue pharse before childen with same event
);

// add a handle that will be removed later
var willRemoved = function() {
  console.log('dispatch-btn:', 6);
};
dispatchBtn.addEventListener('click', willRemoved, false);

// dispatch event after 1s
// then remove it
setTimeout(function() {
  // fire a event
  var event = new Event('click');
  dispatchBtn.dispatchEvent(event);

  // remove event handler
  dispatchBtn.removeEventListener('click', willRemoved, false);
}, 1000);
