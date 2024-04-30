#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);

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
 * lomuto_partition - orders a subset of an array of integers according to
 * the lomuto partition scheme
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the subset
 * @right: ending index of the subset
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_ints(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - applies quicksort algorithm through recursion
 * @array: array of integers to sort
 * @size: size of the array
 * @left: starting index of the array partition
 * @right: ending index of the array partition
 * Description: uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int item;

	if (right - left > 0)
	{
		item = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, item - 1);
		lomuto_sort(array, size, item + 1, right);
	}
}

/**
 * quick_sort - sort an array of integers in ascendingly
 * @array: array of integers
 * @size: size of the array
 * Description: uses the Lomuto partition scheme
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
