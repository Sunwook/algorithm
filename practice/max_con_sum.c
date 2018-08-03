
#include <stdlib.h>
#include <stdio.h>

#define MAX_ARRAY	1000

int data[MAX_ARRAY] = {0,};


int max_consecutive_sum(int s[], int n)
{
	int i, j, k;
	int sum = 0;
	int max_sum = s[0];

	for (i = 0; i < n; i++) 
	{
		for (j = i; j < n; j++) 
		{
			sum = 0;
			for (k = i; k <= j; k++) 
				sum += s[k];

			if (sum > max_sum)
				max_sum = sum;
		}
	}

	return max_sum;
}

int max_consecutive_sum2(int s[], int n)
{
	int i, j, k;
	int sum = 0;
	int max_sum = s[0];

	for (i = 0; i < n; i++) 
	{
		sum = 0;
		for (j = 0; j < n; j++) 
		{
			sum += s[j];
			if (sum > max_sum)
				max_sum = sum;
		}
	}

	return max_sum;
}

int main()
{
	int count = 0;
	int i, j, n;

	scanf("%d", &n);

	for (i=0; i<n; i++)
		scanf("%d",&data[i]);

	/*
	for (i=0; i<n; i++)
		printf("%d ", data[i]);
		*/

	int result = max_consecutive_sum(data, n);

	printf("\n%d\n", result);

	return 0;
}
