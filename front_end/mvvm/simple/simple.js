var _keys = Object.keys;
var _define = Object.defineProperty;

/**
 * 一个简单模拟 Vue 的 MVVM 模型
 * @param {object} options 配置项
 */
function MVVM(options) {
  this._init(options);
}

MVVM.prototype._init = function(options) {
  this.$el = document.querySelector(options.el);
  this.$data = options.data;
  this.$methods = options.methods;

  // view 和 model 的映射关系
  this._binding = {};

  this._observe(this.$data);
  this._compile(this.$el);
};

MVVM.prototype._observe = function(data) {
  var _this = this;
  var current;
  _keys(data).forEach(key => {
    current = data[key];
    _this._binding[key] = { _directives: [] };
    var binding = _this._binding[key];
    if (current && typeof current === 'object') {
      _this._observe(current);
    }

    _define(data, key, {
      get() {
        return current;
      },
      set(value) {
        if (value !== current) {
          current = value;
          binding._directives.forEach(item => {
            item.update();
          });
          console.log('NEW_VALUE:', current);
        }
      }
    });
  });
};

MVVM.prototype._compile = function(root) {
  var _this = this;
  var nodes = root.children;
  var i, l, current;

  var bindVModel = function(directive, { name, el, attr }, cb) {
    var exp = current.getAttribute(directive);
    _this._binding[exp]._directives.push(
      new Watcher(name, el, _this, exp, attr)
    );
    cb && cb(exp, el);
  };

  var bindVEvent = function(directive) {
    var exp = current.getAttribute(directive);
    return _this.$methods[exp].bind(_this.$data); // $data 与 $methods 作用域一样
  };

  for (i = 0, l = nodes.length; i < l; ++i) {
    current = nodes[i];
    if (current.children.length) {
      _this._compile(current);
    }

    // bind directives
    if (
      (current.hasAttribute('v-model') &&
        current.tagName.toLowerCase() === 'input') ||
      current.tagName.toLowerCase() === 'textarea'
    ) {
      bindVModel(
        'v-model',
        { name: 'input', el: current, attr: 'value' },
        (exp, el) => {
          current.addEventListener('input', function() {
            _this.$data[exp] = el.value;
          });
        }
      );
    } else if (current.hasAttribute('v-bind')) {
      bindVModel('v-bind', { name: 'text', el: current, attr: 'innerHTML' });
    } else if (current.hasAttribute('v-click')) {
      current.onclick = bindVEvent('v-click');
    } else {
      // other here ...
    }
  }
};

/**
 * 关联 View 和 Model 并负责更新数据
 * @param {String} name 指令名
 * @param {HTMLElement} el 当前 DOM 元素
 * @param {Object} vm MVVM 实例
 * @param {String} exp 指令值表达式
 * @param {String} attr 绑定的属性
 */
function Watcher(name, el, vm, exp, attr) {
  this.name = name;
  this.el = el;
  this.vm = vm;
  this.exp = exp;
  this.attr = attr;
  this.update();
}

Watcher.prototype.update = function() {
  this.el[this.attr] = this.vm.$data[this.exp];
};

const vm = new MVVM({
  el: '#app',
  data: {
    greet: 'hello mvvm'
  },
  methods: {
    update() {
      this.greet = 'update by button';
    }
  }
});

// console.log(vm.$data);
// vm.$data.greet = 'Hello MVVM';
