#include "sort.h"

/**
 * print_merged - to print merged integers
 * @left: poiter to the left sub-array
 * @left_size: size of the left sub-array
 * @right: poiter to the right sub-array
 * @right_size: size of the right sub-array
 *
 * Return: nothing
 */
void print_merged(int *left, size_t left_size, int *right, size_t right_size)
{
	size_t a, b;

	printf("Merging...\n");
	printf("[left]: ");
	for (a = 0; a < left_size; a++)
	{
		printf("%d", left[a]);
		if (a < left_size - 1)
			printf(", ");
	}
	printf("\n");

	printf("[right]: ");
	for (b = 0; b < right_size; b++)
	{
		printf("%d", right[b]);
		if (b < right_size - 1)
			printf(", ");
	}
	printf("\n");
}
/**
 * top_down_merge - merge two sorted subarrays into a single sorted array.
 * @array: input array
 * @left: pointer to left sub-array
 * @left_size: size of left sub-array
 * @right: pointer to right sub-array
 * @right_size: size of right sub-array
 *
 * Return: nothing
 */
void top_down_merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t c, i = 0, j = 0, k = 0;
	int *merged;

	merged = malloc((left_size + right_size) * sizeof(int));
	if (merged == NULL)
	{
		free(merged);
		return;
	}
	print_merged(left, left_size, right, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			merged[k++] = left[i++];
		else
			merged[k++] = right[j++];
	}

	while (i < left_size)
		merged[k++] = left[i++];

	while (j < right_size)
		merged[k++] = right[j++];

	for (k = 0; k < left_size + right_size; k++)
		array[k] = merged[k];
	printf("[Done]: ");

	for (c = 0; c < left_size + right_size; c++)
	{
		printf("%d", array[c]);
		if (c < left_size + right_size - 1)
			printf(", ");
	}
	printf("\n");
	free(merged);
}
/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2;
	size_t left_size = mid;
	size_t right_size = size - mid;
	int *left = array;
	int *right = array + mid;

	if (array == NULL || size < 2)
		return;

	merge_sort(left, left_size);
	merge_sort(right, right_size);

	top_down_merge(array, left, left_size, right, right_size);
}
