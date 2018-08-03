
#include <stdio.h>

#define 	__D

#define 	MAX		200

#define		min(a,b) (a) > (b) ? (b) : (a)

int N, M;
int D[MAX+1][MAX+1];
int ans;


void search(int h, int w, int value)
{
	printf("\n (%d,%d): value(%d)", h, w, value);

	if (h == N && w == M)
	{
		printf(" Done!!!\n");
		if (ans < value)
			ans = value;

		return;
	}

	value += D[h][w];

	if (h+1 <= N)
		search(h+1, w, value);

	if (w+1 <= M)
		search(h, w+1, value);
}


int DP[MAX+1][MAX+1];

int dp(int h, int w)
{
	//printf("DP(%d)\n", n);

	if (h == N && w == M)
		return D[N][M];


	if (DP[h][w])
		return DP[h][w];

	
	int tmp1=-1, tmp2=-1;
	if (h+1 <= N)
		tmp1 = dp(h+1, w);

	if (w+1 <= M)
		tmp2 = dp(h, w+1);


	if (tmp1 > tmp2)
		DP[h][w] = tmp1 + D[h][w];
	else
		DP[h][w] = tmp2 + D[h][w];

	return DP[h][w];
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
		scanf("%d %d", &N, &M);
#ifdef __D
		printf("#%d: %d x %d\n", tc, N, M);
#endif
		for (i=1; i<=N; i++)
		{
			for (j=1; j<=M; j++)
			{
				scanf("%d", &D[i][j]);
#ifdef __D
				printf("%d ", D[i][j]);
#endif
			}
#ifdef __D
			printf("\n");
#endif
		}


		// ALGO
		ans = 0;

		// #1 BT
		//search(1,1,0);

		// #2 DP
		ans = dp(1,1);

		// #3 DP (iter)
		/*
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
		*/

		
		// OUTPUT

#ifdef __D
		//for (i=1; i<=N; i++)
		//	printf("\ndp(%d): %d", i, dp[i]);

		printf("\nanswer: ");
#endif
		printf("%d\n", ans);

#ifdef __D
		printf("------------------\n\n");
#endif

		// Clear
	}


	return 0;
}

