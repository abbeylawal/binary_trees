#include "binary_trees.h"
/**
 * binary_tree_insert_left - add a node in the left of the parent
 * if it exists it move down one level and add the new node first
 * @parent: parent of the specified node
 * @value: value of the node
 * Return: NULL if it fails or the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
// Allocate memory for the new node
	binary_tree_t *new_node;

	// Check if the parent node is NULL
	if (parent == NULL)
	{
		return (NULL);
	}

	// Create a new node with the given value and parent node
	new_node = binary_tree_node(parent, value);

	// Check if the creation of the new node failed
	if (new_node == NULL)
	{
		return (NULL);
	}

	// If the parent node already has a left child
	if (parent->left != NULL)
	{
		// Set the new node as the left child of the parent node
		new_node->left = parent->left;
		// Set the parent pointer of the old left child to the new node
		parent->left->parent = new_node;
	}

	// Set the new node as the left child of the parent node
	parent->left = new_node;

	// Return a pointer to the newly inserted node
	return (new_node);
}
