#include "sort.h"

/**
 * quick_sort - sorts an array of integers using Quick sort algorithm
 * @array: array of numbers
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	sort_array(array, 0, (size - 1), size);
}

void sort_array(int *array, int min, int max, size_t size)
{
	int temp, current = min, reference = max, lowerbound = min, higherbound = max;

	if (min == max || min > max || max < min)
		return;

	while (lowerbound != higherbound)
	{
		if ((reference == higherbound && array[reference] <= array[current]) || (reference == lowerbound && array[reference] >= array[current]))
		{
			temp = array[current];
			array[current] = array[reference];
			array[reference] = temp;
			if (reference == higherbound)
			{
				higherbound--;
				current = higherbound;
				reference = lowerbound;
			}
			else
			{
				lowerbound++;
				current = lowerbound;
				reference = higherbound;
			}
			print_array(array, size);
		}
		else if (reference == higherbound)
		{
			lowerbound++;
			current = lowerbound;
		}
		else if (reference == lowerbound)
		{
			higherbound--;
			current = higherbound;
		}
	}
	sort_array(array, min, current - 1, size);
	sort_array(array, current + 1, max, size);
}
