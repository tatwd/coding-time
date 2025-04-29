var { TreeNode, utils } = require('../dtype');

/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
  if (!p && !q) return true;
  if (!p || !q) return false;
  if (p.val !== q.val) return false;
  return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
};

// 测试
var tree1 = utils.tree(1, 2, 3);
var tree2 = utils.tree(1, 2, 3);
var tree3 = utils.tree(1, 2, 1);
console.log(
  isSameTree(tree1, tree2),
  isSameTree(tree1, tree3)
);
