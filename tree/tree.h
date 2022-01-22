#ifndef TREE_H
#define TREE_H

#ifndef element_t
#define element_t int
#endif /* element_t */

struct tree_node_t;

struct tree_node_t *tree_new(element_t);
void tree_free(struct tree_node_t *);
element_t tree_node_val(struct tree_node_t *);
void tree_each(struct tree_node_t *, void (*each)(element_t));
void tree_insert_child(struct tree_node_t *, struct tree_node_t *);
void tree_insert_sibling(struct tree_node_t *, struct tree_node_t *);
struct tree_node_t *build_tree(element_t arr[], int len);

#endif /* TREE_H */
