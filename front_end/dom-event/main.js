const container = document.querySelector('#container');
const btn = document.querySelector('#btn');

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
