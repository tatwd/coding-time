// 使用两个栈实现队列

function push(node) {
  stack1.push(node);
}

function pop() {
  /*
  var stack2 = [];
  while (stack1.length > 0)
    stack2.push(stack1.pop());
  var first = stack2.pop();
  while (stack2.length > 0)
    stack1.push(stack2.pop());
  return first;
  */

  if (!stack2.length) {
    while (stack1.length > 0) {
      stack2.push(stack1.pop());
    }
  }
  return stack2.pop();
}

var stack1 = [],
  stack2 = [];

// 测试
var arr = [1, 2, 3, 5, 6];
for (var item of arr) {
  push(item);
}
console.log(stack1);
console.log(pop());
push(7);
console.log(pop());
push(8);
console.log(stack1);
