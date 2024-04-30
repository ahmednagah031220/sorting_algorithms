#include "sort.h"

/**
 * swap_ints - swap two integers in an array
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
 * shell_sort - sorts an array of integers in ascendingly
 * @array: array of integers
 * @size: size of the array
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t diff, i, j;

	if (array == NULL || size < 2)
		return;

	for (diff = 1; diff < (size / 3);)
		diff = diff * 3 + 1;

	for (; diff >= 1; diff /= 3)
	{
		for (i = diff; i < size; i++)
		{
			j = i;
			while (j >= diff && array[j - diff] > array[j])
			{
				swap_ints(array + j, array + (j - diff));
				j -= diff;
			}
		}
		print_array(array, size);
	}
}
