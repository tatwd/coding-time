/**
 * The Vue(2.x-next) version's reactivity system will be rewritten with Proxies.
 * more infomations in https://www.vuemastery.com/courses/advanced-components/evan-you-on-proxies/
 */

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

function watcher(cb) {
  target = cb;
  target();
  target = null;
}

let data = { price: 5, quantity: 2 };
let target = null;

// Map<string, Dep>
let deps = new Map();
Object.keys(data).forEach(key => {
  deps.set(key, new Dep());
});

let data_without_proxy = data;
data = new Proxy(data_without_proxy, {
  get(obj, key) {
    deps.get(key).depend();
    return obj[key];
  },
  set(obj, key, newVal) {
    obj[key] = newVal;
    deps.get(key).notify();
    return true;
  }
});

let total = 0;
watcher(() => {
  total = data.price * data.quantity;
});

console.log(total);
data.price = 20;
console.log(total);
