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
	int lesser, temp;
	char change;

	if (array == NULL)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		change = 'f';
		lesser = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[lesser] > array[j])
			{
				lesser = j;
				change = 't';
			}
		}
		if (change == 't')
		{
			temp = array[lesser];
			array[lesser] = array[i];
			array[i] = temp; 
			print_array(array, size);
		}

	}
}
