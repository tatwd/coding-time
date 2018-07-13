const _keys = Object.keys;
const _define = Object.defineProperty;
/*
const bind = function(dom) {
  return {
    dom: dom,
    text: value => dom.innerText(value),
    html: value => dom.innerHTML(value)
  };
};
*/

function MVVM(obj) {
  this.el = document.querySelector(obj.el);
  this.data = {};

  const keys = _keys(obj.data);
  keys.forEach(key => {
    // init
    const vmdom = this.el.querySelector(`[v-model=${key}]`);
    const vtext = this.el.querySelector(`[v-text=${key}]`);
    if (vmdom && vtext) {
      const _this = this;
      vtext.innerText = obj.data[key];
      _define(vmdom, 'value', {
        get: () => _this.data[key],
        set: newValue => {
          console.log('ok');
          _this.data[key] = newValue;
          vtext.innerText = newValue;
        },
        configurable: true,
        enumerable: true
      });
    }

    // 读写拦截
    _define(this.data, key, {
      get: () => {
        return obj.data[key];
      },
      set: value => {
        obj.data[key] = value;
        // update view here
      },
      configurable: true,
      enumerable: true
    });
  });
}

const vm = new MVVM({
  el: '#app',
  data: {
    greet: 'hello mvvm'
  }
});

// console.log(vm.data.greet);
// vm.data.greet = 'hello';
// console.log(vm.data.greet);
