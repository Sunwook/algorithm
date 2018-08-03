
#include <stdio.h>

#define 	__D

#define 	MAX			20
#define 	V_MAX		100

int D[MAX+1];
int N, min;
int A,B,C;
int sum;

void search(int k, int a, int b, int c)
{
#ifdef __D
	//printf("k(%d), a(%d), b(%d), c(%d)\n", k, a, b, c);
#endif
	if (k == N)
	{
		if (a < b || b < c)
			return;

		//printf("k(%d), a(%d), b(%d), c(%d)\n", k, a, b, c);

		int d = a - c;
		if (d < min)
		{
			min = d;
			A = a;
			B = b;
			C = c;
		}
		else if (d == min)
		{
			if (A > a)
			{
				A = a;
				B = b;
				C = c;
			}
		}

		return;
	}

	int check = sum - a - b - c;
	if (check + a < b || check + b < c)
		return;

	k++;
	int tmp = D[k];
	search(k, a + tmp, b, c);
	search(k, a, b + tmp, c);
	search(k, a, b, c + tmp);
}

int main(void)
{ 
	int T, tc;
	int i, j;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
#ifdef __D
		printf("#%d N: %d\n", tc, N);
#endif
		for (i=1; i<=N; i++)
		{
			scanf("%d", &D[i]);
#ifdef __D
			printf("%d ", D[i]);
#endif
			sum += D[i];

		}
#ifdef __D
		printf("\n");
#endif

		// ALGO
		min = 2000;
		A = 2000;
		search(0, 0, 0, 0);


		// OUTPUT

#ifdef __D
		printf("\nans: Diff(%d),  ", A - C);
#endif
		printf("%d %d %d\n", A, B, C);
#ifdef __D
		printf("----------------\n\n");
#endif

		// Clear

	}

	return 0;
}
