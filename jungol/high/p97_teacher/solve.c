
#include <stdio.h>

#define 	__D

#define 	MAX		1000
#define		INF		987654321

#define		min(a,b) (a) > (b) ? (b) : (a)

int F, N;
int D[4];
int ans;


void search(int k, int n, int dist)
{
	printf("\nk(%d), dist(%d)", k, dist);

	if (dist == n)
	{
		printf(" CHECK!!!\n");
		if (ans > k)
			ans = k;

		return;
	}

	if (dist > n)
		return;

	if (ans < k)
	{
		printf(" PRUNING!!!\n");
		return;
	}

	int i;
	for (i=1; i<=3; i++)
	{
		search(k+1, n, dist + D[i]);
	}

}

int dp[MAX+1];

int DP(int n)
{
	printf("DP(%d)\n", n);

	if (n == 1)
		return 0;

	if (n < 1)
		return -1;

	if (dp[n])
		return dp[n];

	int min = INF;
	
	int i, tmp;
	for (i=1; i<=3; i++)
	{
		if (n-D[i] >= 0)
		{
			tmp = DP(n-D[i]) + 1;
		}

		if (min > tmp)
			min = tmp;
	}

	dp[n] = min;

	return min;
}

int main(void)
{ 
	int tc, T;
	int i,j;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &F, &N);
#ifdef __D
		printf("#%d: Teacher(%d)  Thief(%d)\n", tc, F, N);
#endif
		for (i=1; i<=3; i++)
		{
			scanf("%d", &D[i]);
#ifdef __D
			printf("%d ", D[i]);
#endif
		}


		// ALGO

		// #1 BT
		//ans = INF;
		//search(0, N, F);

		// #2 DP
		//ans = DP(N);

		// #3 DP (iter)
		for (i=F; i<=N; i++)
			dp[i] = INF;

		dp[F] = 0;
		int tmp;
		for (i=2; i<=N; i++)
		{
			tmp = INF;
			for (j=1; j<=3; j++)
			{
				if (i-D[j] > 0)
				{
					tmp = min(tmp, dp[i - D[j]] + 1);
				}
			}
			dp[i] = tmp;
		}
		ans = dp[N];

		
		// OUTPUT

#ifdef __D
		for (i=1; i<=N; i++)
			printf("\ndp(%d): %d", i, dp[i]);

		printf("\nanswer: ");
#endif
		if (ans == INF)
			ans = -1;
		printf("%d\n", ans);

#ifdef __D
		printf("------------------\n\n");
#endif

		// Clear
	}


	return 0;
}

