#include "rb_trees.h"

/**
 * redViolation - checks if there is a red violation
 * @tree: is the tree
 * Return: 1 in success, 0  in case of a red violation
 */
int redViolation(const rb_tree_t *tree)
{
	rb_tree_t *left = NULL, *right = NULL;

	if (!tree)
		return (1);

	left = tree->left, right = tree->right;
	/* Red property and check wheter nodes are just red or black*/
	if ((tree->color == RED &&
		 !(((!left) ? True : left->color == BLACK)
		 && ((!right) ? True : right->color == BLACK))) ||
		(tree->color != RED && tree->color != BLACK))
		return (0);

	/* BST property*/
	if (!(((!left) ? True : left->n < tree->n)
		&& ((!right) ? True : right->n >= tree->n)))
		return (0);

	return (redViolation(tree->left) && redViolation(tree->right));
}

/**
 * blackViolation - check if there is a black violation
 * @tree: is the tree
 * @leftBlackDepth: is what should be all the black depths
 * @curretBlackHeight: is the current black depth
 * Return: 1 in success , 0 in case of a black violation
 */
int blackViolation(const rb_tree_t *tree, int leftBlackDepth,
	int curretBlackHeight)
{
	int lResult = 0, rResult = 0;

	if (!tree)
		return (leftBlackDepth == curretBlackHeight);

	curretBlackHeight += tree->color == BLACK ? 1 : 0;

	lResult = blackViolation(tree->left, leftBlackDepth, curretBlackHeight);
	rResult = blackViolation(tree->right, leftBlackDepth, curretBlackHeight);
	return (lResult && rResult);
}

/**
 * rb_tree_is_valid - determines if a given tree is a Red Black tree
 * @tree: is the given tree
 *
 * Return: 1 in success 0 in otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	rb_tree_t *mostLeft = NULL;
	int blackDepth = 1;

	if (!tree || tree->color != BLACK)
		return (0);

	mostLeft = tree->left;
	while (mostLeft)
	{
		blackDepth += mostLeft->color == BLACK;
		mostLeft = mostLeft->left;
	}

	if (!redViolation(tree) || !blackViolation(tree, blackDepth, 0))
		return (0);
	return (1);
}
