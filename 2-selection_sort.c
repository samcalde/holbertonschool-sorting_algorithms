#include "sort.h"

/**
 * selection_sort - sorts an array of integers using Select sort algorithm
 * @array: array of numbers
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i, j;
	int compare, temp;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		compare = array[i];
		for (j = (i + 1); j < size; j++)
		{
			if (compare > array[j])
			{
				temp = array[j];
				array[j] = compare;
				compare = temp;
				print_array(array, size);				
			}
		}
		array[i] = compare;
	}
}
