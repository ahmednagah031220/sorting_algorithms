#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * array_print - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void array_print(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * list_print - Prints a list of integers
 *
 * @list: The list to be printed
 */
void list_print(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
