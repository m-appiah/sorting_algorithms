#include "sort.h"

/**
 * counting_sort - Sorts an array of integers
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int *array_count, max_num = 0;
	size_t i, j = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}

	array_count = malloc((max_num + 1) * sizeof(int));
	if (array_count == NULL)
	{
		free(array_count);
		return;
	}
	for (i = 0; i <= (size_t)max_num; i++)
		array_count[i] = 0;

	for (i = 0; i < size; i++)
		array_count[array[i]]++;

	print_array(array_count, max_num + 1);

	for (i = 0; i <= (size_t)max_num; i++)
	{
		while (array_count[i] > 0)
		{
			array[j] = (int)i;
			j++;
			array_count[i]--;
		}
	}

	free(array_count);
}
