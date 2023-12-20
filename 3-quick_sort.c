#include "sort.h"
/**
 * swap - swaps integers in an array
 * @a: one of the integers to be swapped in an array
 * @b: the other integer in the array to be swapped
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition_scheme - partition scheme for the array
 * @array: the array of integers
 * @size: the size of the array
 * @high: the last index of the array
 * @low: the starting index of the array
 *
 * Return: final partition index
 */
int lomuto_partition_scheme(int *array, size_t size, int high, int low)
{
	int i, j, *pivot;

	pivot = array + high;
	for (i = j = low; j < high; j++)
	{
		if (array[j] < *pivot)
		{
			if (i  < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;

		}
	}
	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}
/**
 * sorting - recursive function to perform the sorting
 * @array: the array of integers to be sorted
 * @size: the size of the array
 * @high: the last index of the array
 * @low: the starting index of the array
 */
void sorting(int *array, size_t size, int high, int low)
{
	int index;

	if (low < high)
	{
		index = lomuto_partition_scheme(array, size, high, low);
		sorting(array, size, index - 1, low);
		sorting(array, size, high, index + 1);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array of integers
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	sorting(array, size, size - 1, 0);

}
