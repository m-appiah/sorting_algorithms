#include "sort.h"

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 * @array: The array to be partitioned.
 * @low: The index of the low element.
 * @high: The index of the high element.
 * @size: The size of the array.
 *
 * Return: The index of the pivot element.
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, temp, i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
			{
				print_array(array, size);
			}
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
	{
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_lomuto - Sorts an array of integers using the Lomuto partition
 * @array: array to be sorted
 * @low: index of the low element
 * @high: index of the high element
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort_lomuto(int *array, int low, int high, size_t size)
{
	size_t pivot_idex;

	if (low < high)
	{
		pivot_idex = lomuto_partition(array, low, high, size);

		if (pivot_idex > 0)
			quick_sort_lomuto(array, low, pivot_idex - 1, size);
		quick_sort_lomuto(array, pivot_idex + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_lomuto(array, 0, size - 1, size);
}
