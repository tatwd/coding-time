#include <stdio.h>

#include "tree.h"

void each(element_t v) { printf("%d ", v); }

int main(void)
{

	/*
	  1
	 /
	2 —— 3 —— 5 —— 7
			 /
			6
	*/
	// struct tree_node_t *root = tree_new(1);

	// tree_insert_child(root, tree_new(2));
	// tree_insert_child(root, tree_new(3));

	// struct tree_node_t *node5 = tree_new(5);
	// tree_insert_child(root, node5);
	// tree_insert_sibling(node5, tree_new(7));
	// tree_insert_child(node5, tree_new(6));
	// tree_each(root, each);

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	struct tree_node_t *root = build_tree(arr, 10);
	tree_each(root, each);

	tree_free(root);
	return 0;
}
