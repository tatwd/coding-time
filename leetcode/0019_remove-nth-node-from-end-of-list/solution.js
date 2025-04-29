var { ListNode, utils } = require('../dtype');

/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
  var p = head,
    q = head,
    prev = null,
    count = 0;
  while (p) {
    if (count <= n - 1) {
      count++;
    } else {
      prev = q;
      q = q.next;
    }
    p = p.next;
  }

  // 当 n 值大于节点数返回原链表
  if (count < n) return head;

  // 删除第 1 个节点时
  if (prev === null) return q.next;

  prev.next = q.next;
  return head;
};

var data = [
  { head: utils.arr2list([1]), n: 1 },
  { head: utils.arr2list([1, 2]), n: 3 },
  { head: utils.arr2list([1, 2, 3, 4, 5]), n: 5 }
];
for (var i of data) {
  var result = removeNthFromEnd(i.head, i.n);
  console.log(utils.list2arr(result));
}
/*
[]
[ 1, 2 ]
[ 2, 3, 4, 5 ]
*/
