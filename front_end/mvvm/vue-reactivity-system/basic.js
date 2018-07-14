// solution 1
/*
let price = 5;
let quantity = 2;
let total = 0;
let target = null;
let storge = [];

target = () => {
  total = price * quantity;
};

function record() {
  storge.push(target);
}

function replay() {
  storge.forEach(run => run());
}

record();
target();

price = 20;
console.log(total);
replay();
console.log(total);
*/

// solution 2
/*
class Dep {
  constructor() {
    this.subscribers = [];
  }

  depend() {
    if (target && !this.subscribers.includes(target)) {
      this.subscribers.push(target);
    }
  }

  notify() {
    this.subscribers.forEach(sub => sub());
  }
}

const dep = new Dep();

let price = 5;
let quantity = 2;
let total = 0;

// let target = () => {
//   total = price * quantity;
// };

// add this target to subscribers
// dep.depend();

// get total value
// target();

function watcher(cb) {
  target = cb;
  dep.depend();
  target();
  target = null;
}

watcher(() => {
  total = price * quantity;
});

price = 20;
console.log(total);
dep.notify();
console.log(total);
*/

// solution 3
let data = {
  price: 5,
  quantity: 2
};
let target = null;

class Dep {
  constructor() {
    this.subscribers = [];
  }

  depend() {
    if (target && !this.subscribers.includes(target)) {
      this.subscribers.push(target);
    }
  }

  notify() {
    this.subscribers.forEach(sub => sub());
  }
}

Object.keys(data).forEach(key => {
  let current = data[key];
  const dep = new Dep();
  Object.defineProperty(data, key, {
    get() {
      dep.depend();
      return current;
    },
    set(value) {
      current = value;
      dep.notify();
    }
  });
});

function watcher(cb) {
  target = cb;
  target();
  target = null;
}

watcher(() => {
  data.total = data.price * data.quantity;
});

console.log(data.total);
data.price = 20;
console.log(data.total);
