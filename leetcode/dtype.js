// A singly-linked list.
function ListNode(val) {
  this.val = val;
  this.next = null;
}

// A binary tree node.
function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}

// Some utils
var utils = {
  arr2list(arr) {
    if (!arr.length) return null;
    var list = new ListNode(arr[0]);
    var p = list;
    for (var i = 1, l = arr.length; i < l; ++i) {
      p.next = new ListNode(arr[i]);
      p = p.next;
    }
    return list;
  },

  list2arr(list) {
    var arr = [];
    var p = list;
    while (p) {
      arr.push(p.val);
      p = p.next;
    }
    return arr;
  },

  tree(v, l, r) {
    if (!v) return null;
    var root = root = new TreeNode(v);
    l && (root.left = new TreeNode(l));
    r && (root.right = new TreeNode(r));
    return root;
  }
};

module.exports = {
  ListNode,
  TreeNode,
  utils
};
