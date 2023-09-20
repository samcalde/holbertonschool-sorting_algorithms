#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers using Insertion algorithm
 * @list: list to arrange
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL;

	if (list == NULL || *list == NULL)
		return;

	temp = (*list)->next;

	while (temp != NULL)
	{
		if (temp->n < temp->prev->n)
			check_nodes_backwards(temp, list);
		temp = temp->next;
	}
}

/**
 * check_nodes_backwards - checks for matches up to the beggining of list
 * @node: node to start
 * @list: list to print, or pass to swap to update head of list
 *
 * Return: void
 */
void check_nodes_backwards(listint_t *node, listint_t **list)
{
	if (node->prev == NULL)
		return;

	if (node->n < node->prev->n)
	{
		swap_nodes(node->prev, node, list);
		print_list(*list);
		check_nodes_backwards(node, list);
	}
}

/**
 * swap_nodes - swaps node A and B on a doubled linked list
 * @nodeA: node A, which goes first in the list
 * @nodeB: node B, which goes after node A
 * @list: head of the list, in case it needs to be updated
 *
 * Return: void
 */
void swap_nodes(listint_t *nodeA, listint_t *nodeB, listint_t **list)
{
	nodeA->next = nodeB->next;
	nodeB->prev = nodeA->prev;
	nodeA->prev = nodeB;
	nodeB->next = nodeA;

	if (nodeA->next != NULL)
		nodeA->next->prev = nodeA;

	if (nodeB->prev != NULL)
		nodeB->prev->next = nodeB;

	if (nodeB->prev == NULL)
		*list = nodeB;
}
