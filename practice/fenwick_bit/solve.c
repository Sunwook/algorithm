
// https://www.acmicpc.net/blog/view/21
// https://www.acmicpc.net/problem/2042

#define 	__D

// Jungol(M), p283

#define 	V_MAX		10
#define 	E_MAX		30
#define		VALUE_MAX	200

#define 	INF		987654321

int D[V_MAX+1][V_MAX+1];
//int VISIT[V_MAX+1];
//int Q[V_NAX+1];
int queue;
int DIST[V_MAX+1];
int ans;
int V, E;

int get_min(int q)
{
	int i,min_i, min = INF;
	for (i=0; i<V; i++)
	{
		if (q & (1 << i))
			if (DIST[i] < min)
			{
				min = DIST[i];
				min_i = i;
			}
	}

	return min_i + 1;
}

void print_data(int v)
{
	int i,j;
	printf("\nresult: \n");

	for (i=1; i<=v; i++)
		printf("%d ", DIST[i]);

	printf("\n");
}

int main(void)
{ 
	int T, tc, N;
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

		DIST[1] = 0;
		for (i=2; i<=V; i++)
		{
			DIST[i] = D[1][i];
		}

		queue = (1 << V) - 1;
		int v;
		while (queue != 0)
		{
			// Get a min v in the queue
			v = get_min(queue);

			// Remove from the queue
			queue = queue & ~(1 << (v-1));

			// Get neighbors
			for (i=1; i<=V; i++)
			{
				if (D[v][i] != INF)
				{
					if (DIST[i] > DIST[v] + D[v][i])
						DIST[i] = DIST[v] + D[v][i];
				}
			}
		}
		

		ans = DIST[V];

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
