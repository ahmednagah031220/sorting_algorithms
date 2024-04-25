#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts and arrya of integers ascendingly
 * @array: array of integers to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t element, length = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (element = 0; element < length - 1; element++)
		{
			if (array[element] > array[element + 1])
			{
				swap_ints(array + element, array + element + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		length--;
	}
}

