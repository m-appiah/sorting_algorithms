#include "sort.h"

/**
 * sift_down - function to sift-down operation on the heap using heapsort
 * @array: array to be sorted as a binary heap
 * @size: size of the heap
 * @start: root/parent of the heap subtree
 * @end: last element of the heap
 *
 * Return: nothing
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t parent = start;
	size_t child, swap;
	int temp;

	while (2 * parent + 1 <= end)
	{
		child = 2 * parent + 1;
		swap = parent;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap == parent)
			return;

		temp = array[parent];
		array[parent] = array[swap];
		array[swap] = temp;

		print_array(array, size);

		parent = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
