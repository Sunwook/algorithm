
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int arr[SIZE] = {79,30,24,48,26,34,5,48,21,86};

void quickSort(int left, int right) {
	int i = left, j = right;
	int tmp;
	//int pivot = arr[(left + right) / 2];
	int pivot = arr[left];

	// partition
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	// recursion 
	if (left < j)
		quickSort(left, j);
	if (i < right)
		quickSort(i, right);
}

void printData()
{
	int i=0;

	printf("Data: ");

	for(i=0; i<SIZE; i++)
	{
		printf("%d ", arr[i]);
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
