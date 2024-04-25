#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble - sorts and arrya of integers ascendingly
 * @array: array of integers to sort
 * @size: size of the array
 */
void bubble(int *array, size_t size)
{
	size_t element, len = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (element = 0; element < len - 1; element++)
		{
			if (array[element] > array[element + 1])
			{
				swap_ints(array + element, array + element + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		len--;
	}
}

