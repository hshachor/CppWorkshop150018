#include "SortAndPrint.h"
void SortAndPrint::setSize(int num)
{
	size = num;
}

void SortAndPrint::print()
{
	for (int i = 0; i < size; i++)
		show(i);
}

void SortAndPrint::bubbleSort()
{
	for (int last = size - 1; last > 0; last--)
		for (int i = 0; i < last; i++)
			if (isSmaller(i + 1, i))
				swap(i, i + 1);
}
