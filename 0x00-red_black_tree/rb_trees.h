#ifndef _RB_TREES_H
#define _RB_TREES_H

#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

#define SON_PARENT_RED(parent, node) \
	((parent->color == RED) && (node->color == RED))
#define GETPARENT(node) ((node == NULL) ? NULL : node->parent)
#define GETANCESTOR(node) GETPARENT(GETPARENT(node))
#define GETSIBLING(node) \
	(GETPARENT(node) ? \
	((node == (GETPARENT(node)->left)) ? \
	(GETPARENT(node)->right) : \
	(GETPARENT(node)->left)) : \
	NULL)
#define GETUNCLE(node) GETSIBLING(GETPARENT(node))
#define LEFT_LEFT_CASE(node) \
	((GETPARENT(node) && GETANCESTOR(node)) && \
	(GETPARENT(node) == GETANCESTOR(node)->left) && \
	(node == GETPARENT(node)->left))
#define LEFT_RIGHT_CASE(node) \
	((GETPARENT(node) && GETANCESTOR(node)) && \
	(GETPARENT(node) == GETANCESTOR(node)->left) && \
	(node == GETPARENT(node)->right))
#define RIGHT_RIGHT_CASE(node) \
	((GETPARENT(node) && GETANCESTOR(node)) && \
	(GETPARENT(node) == GETANCESTOR(node)->right) && \
	(node == GETPARENT(node)->right))
#define RIGHT_LEFT_CASE(node) \
	((GETPARENT(node) && GETANCESTOR(node)) && \
	(GETPARENT(node) == GETANCESTOR(node)->right) && \
	(node == GETPARENT(node)->left))
#define COLOR_SWAP(node, parent, tmp) \
	(tmp = node->color, node->color = parent->color, parent->color = tmp)
/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: 2 -> Double-black node (used for deletion)
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
int rb_tree_is_valid(const rb_tree_t *tree);
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);
void insert_fixup(rb_tree_t **tree, rb_tree_t *node);
void rigthRotate(rb_tree_t *node, rb_tree_t **root);
void leftRotate(rb_tree_t *node, rb_tree_t **root);

#endif/* _RB_TREES_H */
