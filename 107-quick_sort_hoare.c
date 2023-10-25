#include "sort.h"

/**
 * hoare_partition - function to partition array
 * @array: array to be sorted
 * @size: size of the array
 * @low: low index of the partition
 * @high: high index of the partition
 *
 * Return: index of the pivot
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int temp, i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
			i++;
		while (array[i] < pivot);

		do
			j--;
		while (array[j] > pivot);

		if (i >= j)
			return (j);

		temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		print_array(array, size);
	}
}

/**
 * quicksort_hoare - Sorts an array of integers
 * @array: array to be sorted
 * @size: size of the array
 * @low: low index of the partition
 * @high: high index of the partition
 *
 * Return: nothing
 */
void quicksort_hoare(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, size, low, high);
		quicksort_hoare(array, size, low, pivot);
		quicksort_hoare(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort_hoare - quick sort with hoare
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, size, 0, size - 1);
}
