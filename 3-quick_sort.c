#include "sort.h"

/**
 * swap - swap two ints
 * @a: 1st int
 * @b: 2nd int
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = 0;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * lomuto - lomuto partition scheme
 * @array: the array to sort
 * @low: starting point
 * @high: ending point
 * @size: size of array
 * Return: the partition index
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int ross = array[high];
	int i = low - 1, j = 0;

	for (j = low; j < high; j++)
	{
		if (array[j] < ross)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort_rec- recursively sort an array using quicksort
 * @array: the array to sort
 * @low: starting point
 * @high: ending point
 * @size: size of array
 * Return: void
 */
void quicksort_rec(int *array, int low, int high, size_t size)
{
	int i = 0;

	if (low < high)
	{
		i = lomuto(array, low, high, size);
		quicksort_rec(array, low, i - 1, size);
		quicksort_rec(array, i + 1, high, size);
	}
}
/**
 * quick_sort- sorts an array using quick sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_rec(array, 0, size - 1, size);
}
