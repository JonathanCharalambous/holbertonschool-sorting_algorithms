#include "sort.h"


/**
 * bubble_sort- sorts an array using bubble sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int t = 0;
	int swap = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
				swap = 1;
				print_array(array, size);
			}
		}

		if (!swap)
			break;
	}
}
