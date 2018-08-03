
#include <stdio.h>
#include <stdlib.h>

//#define SIZE 10
#define SIZE 5

//int data[SIZE] = {79,30,24,48,26,34,5,48,21,86};
//int data[SIZE] = {79,30,24,48,26};
int data[SIZE] = {30,79,24,48,26};


void swap(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

void quickSort(int left, int right)
{
	int i=left;
	int j=right;
	int pivot = i;

	while(i<j)
	{
		while(data[i]<=data[pivot] && i<j)
			i++;

		while(data[j]>=data[pivot] && i<j)
			j--;

		if (i<j)
			swap(&data[i], &data[j]);
	}

	swap(&data[j], &data[pivot]);

	if (i< left) 
		quickSort(left, j-1);

	if (j>right)
		quickSort(j+1, right);
}

void printData()
{
	int i=0;

	printf("Data = ");

	for(i=0; i<SIZE; i++)
	{
		printf("%d ", data[i]);
	}

	printf("\n");
}

int main()
{
	// Print original data
	printData();

	quickSort(0, SIZE-1);

	// Print sorted data
	printData();

	return 0;
}
