
#include <stdio.h>

#define 	__D

#define 	MAX			500
#define 	V_MAX		1000000

int D[MAX+1][MAX+1];
int VISIT[MAX+1][MAX+1];
int N;
int min, max;
int ans;
int max_climb;

int dh[4] = {0, 0,  1, -1};
int dw[4] = {1, -1, 0,  0};

int dfs(int h, int w, int value)
{
	int cover = 1;
	VISIT[h][w] = 1;
	int i, nh, nw, diff;
	for (i=0; i<4; i++)
	{
		nh = h + dh[i];
		nw = w + dw[i];
		if (nh > 0 && nh <= N && nw > 0 && nw <= N && !VISIT[nh][nw])
		{
			diff = D[nh][nw] - D[h][w];
			if (diff < 0)
				diff *= -1;

			if (diff <= value)
			{
				cover += dfs(nh, nw, value);
			}
		}
	}

	return cover;
}

int check_climb(int value)
{
	int i,j;
	int count, max = 0;

	// reset the visit array
	for (i=1; i<=N; i++)
		for (j=1; j<=N; j++)
			VISIT[i][j] = 0;

	for (i=1; i<=N; i++)
	{
		for (j=1; j<=N; j++)
		{
			if (!VISIT[i][j])
			{
				count = dfs(i, j, value);
				if (count > max)
					max = count;
			}
		}
	}

#ifdef __D
	printf("\ncover (%d)", max);
#endif

	if (max >= max_climb)
		return 1;
	else
		return 0;
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
		min = V_MAX;
		max = 0;
		for (i=1; i<=N; i++)
		{
			for (j=1; j<=N; j++)
			{
				scanf("%d", &D[i][j]);
#ifdef __D
				printf("%d ", D[i][j]);
#endif

				if (D[i][j] > max)
					max = D[i][j];
				if (D[i][j] < min)
					min = D[i][j];
			}
#ifdef __D
			printf("\n");
#endif
		}

#ifdef __D
		printf("\nmin(%d), max(%d)", min, max);
#endif
		// ALGO
		max_climb = 0.75 * N * N;
		int mid;
		int done = 0;
		while(min <= max) 
		{
			mid = (min + max) / 2;
#ifdef __D
			printf("\nmid(%d)", mid);
#endif

			if (check_climb(mid))
			{
#ifdef __D
				printf("\nclimbed!!");
#endif
				ans = mid;
				max = mid - 1;
			}
			else
			{
#ifdef __D
				printf("\ncan't be climbed!!");
#endif
				min = mid + 1;
			}

		}

		// OUTPUT
#ifdef __D
		printf("\nans: ");
#endif
		printf("%d\n", ans);


	}

	return 0;
}
