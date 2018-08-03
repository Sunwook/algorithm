
// https://www.acmicpc.net/problem/1149

#include <stdio.h>

#define 	__D

#define 	MAX		1000
#define		COLOR_N		3	

int COLOR[MAX+1][COLOR_N+1];
int D[MAX+1][COLOR_N+1];

int ans;
int N;

int main(void)
{ 
	int T, tc;
	int i, j, k;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	//scanf("%d", &T);
	T = 1;
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
#ifdef __D
		printf("#%d N: %d\n", tc, N);
#endif
		for (i=1; i<=N; i++)
		{
			for (j=1; j<=COLOR_N; j++)
			{
				scanf("%d", &COLOR[i][j]);
#ifdef __D
				printf("%d ", COLOR[i][j]);
#endif
				D[i][j] = 0;
			}
#ifdef __D
			printf("\n");
#endif
		}

		// ALGO

		ans = 10000000;
		for (i=1; i<=N; i++)
			D[1][i] = COLOR[1][i];

		int min;
		for (i=2; i<=N; i++)
		{
			for (j=1; j<=COLOR_N; j++)
			{
				D[i][j] = COLOR[i][j];
				min = 10000000;
				for (k=1; k<=COLOR_N; k++)
				{
					if (k != j)
					{
						if (min >= D[i-1][k])
							min = D[i-1][k];
					}
				}

				D[i][j] += min;
			}
		}


		ans = D[N][1];
		for (j=2; j<=COLOR_N; j++)
		{
			if (ans >= D[N][j])
				ans = D[N][j];
		}

		// OUTPUT
#ifdef __D
		printf("ans: ");
#endif
		printf("%d\n", ans);

#ifdef __D
		printf("\n");
#endif
		// Clear
	}

	return 0;
}
