
#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) 
{
	int tmp = *a; 
	*a = *b; 
	*b = tmp;
}

void quick(int* data, int left, int right)
{
	int pivot, p, q;
	if (left >= right)
		return;

	pivot = data[left];
	p = left +1;
	q = right;

	while(p <= q)
	{
		while(pivot > data[p])
			p++;

		while(pivot < data[q])
			q--;

		if (p <= q)
			swap(&data[p], &data[q]);
		else
		{
			swap(&data[left], &data[q]);
			break;
		}
	}

	quick(data, left, q-1); // small group
	quick(data, q+1, right); // large group
}

void print_data(int *data, int num)
{
	int i;

	for (i=0; i<num; i++)
	{
		printf("%d ", data[i]);
	}

	printf("\n");
}

int main()
{
	int data[10] = {26, 5, 77, 1, 61, 11, 59, 15, 49, 19};
	int num = 10;
	int i = 0;

	printf("Original data: ");
	print_data(data, num);

	// Sorting
	quick(data, 0, num-1);

	printf("Sorted data: ");
	print_data(data, num);

	return 0;
}

