#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	interval = 1;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval >= 1)
	{

		for (i = interval; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}

			array[j] = temp;
		}

		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
