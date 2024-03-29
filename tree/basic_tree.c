#include <stdlib.h>

#include "tree.h"

struct tree_node_t {
	element_t element;
	struct tree_node_t *first_child;
	struct tree_node_t *next_sibling;
};

struct tree_node_t *tree_new(element_t element)
{
	struct tree_node_t *node = malloc(sizeof(struct tree_node_t));
	node->element = element;
	return node;
}

void tree_free(struct tree_node_t *root)
{
	if (root == NULL)
		return;
	if (root->first_child == NULL && root->next_sibling == NULL)
		free(root);
	else if (root->first_child != NULL)
		tree_free(root->first_child);
	else if (root->next_sibling != NULL)
		tree_free(root->next_sibling);
}

element_t tree_node_val(struct tree_node_t *node)
{
	return node == NULL ? -1 : node->element;
}

void tree_each(struct tree_node_t *root, void (*each)(element_t))
{
	if (root == NULL)
		return;
	each(root->element);
	tree_each(root->next_sibling, each);
	tree_each(root->first_child, each);
}

void tree_insert_child(struct tree_node_t *root, struct tree_node_t *child)
{
	if (root == NULL)
		return;
	if (root->first_child == NULL)
		root->first_child = child;
	else
		tree_insert_sibling(root->first_child, child);
}

void tree_insert_sibling(struct tree_node_t *root, struct tree_node_t *sibling)
{
	if (root == NULL)
		return;
	if (root->next_sibling == NULL)
		root->next_sibling = sibling;
	else
		tree_insert_sibling(root->next_sibling, sibling);
}

/* 从数组的中部开始构建一棵树 */
static struct tree_node_t *build_tree_from_middle(element_t arr[], int left,
												  int right)
{
	if (left > right)
		return NULL;

	int mid = (left + right) / 2;

	struct tree_node_t *root = tree_new(arr[mid]);
	root->first_child = build_tree_from_middle(arr, left, mid - 1);
	root->next_sibling = build_tree_from_middle(arr, mid + 1, right);

	return root;
}

struct tree_node_t *build_tree(element_t arr[], int len)
{
	struct tree_node_t *root = build_tree_from_middle(arr, 0, len - 1);
	return root;
}
