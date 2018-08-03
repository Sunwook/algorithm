
#include <stdio.h>

#define 	__D

// Jungol(M), p283

#define 	V_MAX		10
#define 	E_MAX		30
#define		VALUE_MAX	200

#define 	INF		987654321

int D[V_MAX+1][V_MAX+1];
int ans;

void print_data(int v)
{
	int i,j;
	printf("\nresult: \n");
	for (i=1; i<=v; i++)
	{
		for (j=1; j<=v; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}
}

int main(void)
{ 
	int T, tc, N;
	int V, E;
	int i, j;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &V, &E);
#ifdef __D
		printf("#%d V(%d), E(%d)\n", tc, V, E);
#endif
		for (i=1; i<=V; i++)
		{
			for (j=1; j<=V; j++)
				D[i][j] = D[j][i] = INF;

			D[i][i] = 0;
		}

		int v1, v2, d;
		for (i=1; i<=E; i++)
		{
			scanf("%d %d %d", &v1, &v2, &d);
			D[v1][v2] = D[v2][v1] = d;
		}


		// ALGO


		int k, min;
		for (k=1; k<=V; k++)
			for (i=1; i<=V; i++)
			{
				if (i == k)
					continue;

				for (j=1; j<=V; j++)
				{
					if (j==k || i==j)
						continue;

					if (D[i][k] != INF && D[k][j] != INF)
						if (D[i][j] > D[i][k] + D[k][j])
							D[i][j] = D[i][k] + D[k][j];
				}
			}

		ans = D[1][V];

		// OUTPUT
		print_data(V);

#ifdef __D
		printf("\nans: ");
#endif
		printf("%d\n", ans);

		// RESET
	}



	return 0;
}
