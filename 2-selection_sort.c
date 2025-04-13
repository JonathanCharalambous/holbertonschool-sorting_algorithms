#include "sort.h"


/**
 * selection_sort - sorts an array using selection sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	int tmp = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		k = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}

		if (k != i)
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
			print_array(array, size);
		}
	}

}
