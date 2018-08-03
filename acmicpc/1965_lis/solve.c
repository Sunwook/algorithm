
// https://www.acmicpc.net/problem/1965

#include <stdio.h>

#define 	__D

#define 	MAX		1000

int A[MAX+1];
int D[MAX+1];

int N;

int main(void)
{ 
	int i, j, k, ans;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &N);
#ifdef __D
	printf("N: %d\n", N);
#endif
	for (i=1; i<=N; i++)
	{
		scanf("%d", &A[i]);
#ifdef __D
		printf("%d ", A[i]);
#endif
		D[i] = 0;
	}

	// ALGO
	ans = 1;
	for (i=1; i<=N; i++)
	{
		D[i] = 1;
		for (j=1; j<i; j++)
		{
			if (D[i] <= D[j] && A[i] > A[j])
				D[i] = D[j] + 1;
		}

		if (ans < D[i])
			ans = D[i];
	}

	// OUTPUT
#ifdef __D
	printf("\nans: ");
#endif
	printf("%d\n", ans);

#ifdef __D
	printf("\n");
#endif
	// Clear

	return 0;
}
