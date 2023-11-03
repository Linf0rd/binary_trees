#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
	int front = 0, rear = 0;
	int has_null_child = 0;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *node = queue[front++];

		if (node->left == NULL)
			has_null_child = 1;
		else if (has_null_child)
			return (0);
		else
			queue[rear++] = node->left;

		if (node->right == NULL)
			has_null_child = 1;
		else if (has_null_child)
			return (0);
		else
			queue[rear++] = node->right;
	}

	free(queue);

	return (1);
}
