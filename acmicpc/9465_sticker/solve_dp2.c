#include <stdio.h>

#define __D

#define 	MAX		100005

inline int get_max(int a, int b)
{
	return a > b ? a : b;
}

int MAP[3][MAX];
int DP[3][MAX];
int N;
int main(void)
{ 
	int T, tc;
	int i, j, k, ans;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
#ifdef __D
		printf("%d\n", N);
#endif

		for (i=1; i<=2; i++)
		{
			for (j=1; j<=N; j++)
			{
				scanf("%d", &MAP[i][j]);
				DP[i][j] = 0;
#ifdef __D
				printf("%d ", MAP[i][j]);
#endif
			}
#ifdef __D
			printf("\n");
#endif
		}


		DP[1][1] = MAP[1][1];
		DP[2][1] = MAP[2][1];
		DP[1][2] = MAP[2][1] + MAP[1][2];
		DP[2][2] = MAP[1][1] + MAP[2][2];

		for (j=3; j<=N; j++)
		{
			DP[1][j] = get_max(DP[1][j-2], DP[2][j-2]);
			DP[1][j] = get_max(DP[1][j], DP[2][j-1]);
			DP[1][j] += MAP[1][j];

			DP[2][j] = get_max(DP[1][j-2], DP[2][j-2]);
			DP[2][j] = get_max(DP[2][j], DP[1][j-1]);
			DP[2][j] += MAP[2][j];
		}

		int ans = get_max(DP[1][N], DP[2][N]);
		printf("%d\n", ans);
	}

	return 0;
}
