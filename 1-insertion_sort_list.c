#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly-linked list
 * @h: head of the doubly-linked list pointer
 * @n1: first node pointer to swap
 * @n2: second node pointer to swap
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - implements the insertion sort algorithm
 * @list: pointer to the head of a doubly-linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iteration, *insertion, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iteration = (*list)->next; iteration != NULL; iteration = temp)
	{
		temp = iteration->next;
		insertion = iteration->prev;
		while (insertion != NULL && iteration->n < insertion->n)
		{
			swap_nodes(list, &insertion, iteration);
			print_list((const listint_t *)*list);
		}
	}
}
