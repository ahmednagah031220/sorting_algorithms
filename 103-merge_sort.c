#include "sort.h"

void merge_subarr(int *subarr, int *buffer, size_t front, size_t middle,
		size_t back);
void merge_sort_recursive(int *subarr, int *buffer, size_t front, size_t back);

/**
 * merge_subarr - sorts a subarray of integers
 * @subarr: subarray of an array of integers to sort
 * @buffer: buffer to store the sorted subarray
 * @front: front index of the array
 * @middle: middle index of the array
 * @back: back index of the array
 */
void merge_subarr(int *subarr, int *buffer, size_t front, size_t middle,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, middle - front);

	printf("[right]: ");
	print_array(subarr + middle, back - middle);

	for (i = front, j = middle; i < middle && j < back; k++)
		buffer[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < middle; i++)
		buffer[k++] = subarr[i];
	for (; j < back; j++)
		buffer[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - implements merge sort algorithm
 * @subarr: subarray of an array of integers to sort
 * @buffer: buffer to store the sorted result
 * @front: front index of the subarray
 * @back: back index of the subarray
 */
void merge_sort_recursive(int *subarr, int *buffer, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		merge_sort_recursive(subarr, buffer, front, middle);
		merge_sort_recursive(subarr, buffer, middle, back);
		merge_subarr(subarr, buffer, front, middle, back);
	}
}

/**
 * merge_sort - sorts an array of integers in ascendingly
 * @array: array of integers
 * @size: size of the array
 * Description: implements the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
