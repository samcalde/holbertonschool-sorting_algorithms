#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort algorithm
 * @array: array of numbers
 * @size: size of array
 *
 * Return: Always 0
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;
	int temp;

	if (array == NULL)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
