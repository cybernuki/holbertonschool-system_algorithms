#include "rb_trees.h"

/**
 * insert_fixup - fix the tree
 * @root: is the root node
 * @node: is a node
 */
void insert_fixup(rb_tree_t **root, rb_tree_t *node)
{
	rb_tree_t *parent = NULL, *uncle = NULL, *ancestor = NULL;
	rb_color_t tmpColor = BLACK;

	while ((parent = GETPARENT(node)) && SON_PARENT_RED(parent, node))
	{
		uncle = GETUNCLE(node), ancestor = GETANCESTOR(node);
		if (uncle && uncle->color == RED)
		{
			parent->color = BLACK, uncle->color = BLACK, node = GETANCESTOR(node);
			node->color = RED;
		}
		else if (!uncle || (uncle && uncle->color == BLACK))
		{
			if (LEFT_LEFT_CASE(node))
			{
				rigthRotate(parent, root);
				COLOR_SWAP(parent, ancestor, tmpColor);
			}
			else if (LEFT_RIGHT_CASE(node))
				leftRotate(node, root);
			else if (RIGHT_RIGHT_CASE(node))
			{
				leftRotate(parent, root);
				COLOR_SWAP(parent, ancestor, tmpColor);
			}
			else if (RIGHT_LEFT_CASE(node))
				rigthRotate(node, root);

			node = parent;
		}
	}
	if (!node->parent)
		node->color = BLACK;
}

/**
 * rb_tree_insert - insert a new node in the red black tree
 * @tree: is the tree
 * @value: is the value to be insert
 * Return: a pointer to the new node, NULL in failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *newNode = malloc(sizeof(*newNode));
	rb_tree_t *current = NULL, *previous = NULL;

	if (!tree || !newNode)
		return (NULL);

	memset(newNode, 0, sizeof(*newNode));
	newNode->n = value;
	newNode->color = RED;

	current = *tree;
	while (current)
	{
		previous = current;
		if (value == current->n) {
			free(current);
			return (NULL);
		}
		else if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}
	newNode->parent = previous;
	if (!previous)
		*tree = newNode;
	else if (value < previous->n)
		previous->left = newNode;
	else
		previous->right = newNode;

	insert_fixup(tree, newNode);
	return (newNode);
}

/**
 * rigthRotate - Performes a right rotation of nodes
 * @node: is the node to be rotated
 * @root: is the root of the tree
 */
void rigthRotate(rb_tree_t *node, rb_tree_t **root)
{

	rb_tree_t *parent = GETPARENT(node), *ancestor = GETANCESTOR(node);

	if (!node || !root || !parent || parent->left != node)
		return;

	if (node->right)
		node->right->parent = parent;
	parent->left = node->right;

	parent->parent = node;
	node->right = parent;
	node->parent = ancestor;

	if (!ancestor)
		*root = node;
	else if (parent == ancestor->right)
		ancestor->right = node;
	else
		ancestor->left = node;
}

/**
 * leftRotate - Performes a left rotation of nodes
 * @node: is the node to be rotated
 * @root: is the root of the tree
 */
void leftRotate(rb_tree_t *node, rb_tree_t **root)
{

	rb_tree_t *parent = GETPARENT(node), *ancestor = GETANCESTOR(node);

	if (!node || !root || !parent || parent->right != node)
		return;

	if (node->left)
		node->left->parent = parent;
	parent->right = node->left;

	parent->parent = node;
	node->left = parent;
	node->parent = ancestor;

	if (!ancestor)
		*root = node;
	else if (parent == ancestor->right)
		ancestor->right = node;
	else
		ancestor->left = node;
}
