
#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selection(int *a, int num)
{
	int i, j, min;
	
	for (i=0; i<num; i++)
	{
		min = i;
		for (j=i+1; j<num; j++)
		{
			if (a[j] < a[min])
				min = j;
		}

		swap(&a[i], &a[min]);
	}
}

void bubble(int *a, int num)
{
	int i, j, min;
	
	//for (i=0; i<num; i++)
	for (i=0; i<num-2; i++)
	{
		//for (j=0; j<num-i; j++)
		for (j=1; j<num-i; j++)
		{
			//if (a[j] > a[j+1])
				//swap(&a[j], &a[j+1]);
			if (a[j-1] > a[j])
				swap(&a[j-1], &a[j]);
		}
	}
}

void insert(int *a, int num)
{
	int i, j, value;

	for (i=1; i<num; i++)
	{
		value = a[i];

		for (j=i-1; value < a[j] && j>=0; j--)
		{
			a[j+1] = a[j];
		}

		a[j+1] = value;
	}

}

void shell(int *a, int num)
{
	int i, gap;

	for (gap=num/2; gap>0; gap=gap/2)
	{
		for (i=0; i<gap; i++)
		{
			//insert(a, i, n-1, gap);
		}
	}

}

void print_data(int *a, int num)
{
	int i;

	for (i=0; i<num; i++)
	{   
		printf("%d ", a[i]);
	}   

	printf("\n");
}

void (*func)(int *a, int num);

int main()
{
	int data[10] = {26, 5, 77, 1, 61, 11, 59, 15, 49, 19};
	int num = 10;

	// Sort function
	func = bubble;

	printf("Original data: ");
	print_data(data, num);

	// Sorting
	func(data, num);

	printf("Sorted data: ");
	print_data(data, num);

	return 0;
}

