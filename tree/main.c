#include <stdio.h>

#include "tree.h"

void each(element_t v)
{
	printf("%d ", v);
}

int main(void)
{
	struct tree_node_t *root = tree_new(1);

/*
  1
 /
2 —— 3 —— 5 —— 7
         /
        6
*/

	tree_insert_child(root, tree_new(2));
	tree_insert_child(root, tree_new(3));

	struct tree_node_t *node5 = tree_new(5);
	tree_insert_child(root, node5);
	tree_insert_sibling(node5, tree_new(7));
	tree_insert_child(node5, tree_new(6));
	tree_each(root, each);

	tree_free(root);
	return 0;
}
