#include <stdio.h>

#define __D

#define 	MAX		100005

inline int get_max(int a, int b)
{
	return a > b ? a : b;
}

int MAP[3][MAX];
int DP[4][MAX];

int N;
int solve(int index, int pCheck)
{
#ifdef __D
	printf("index(%d), pCheck(%d)\n", index, pCheck);
#endif

	if (index == N+1)
		return 0;

	if (DP[index][pCheck])
		return DP[index][pCheck];

	int max = 0;
	if (pCheck == 0)
	{
		max = get_max(max, solve(index + 1, 0));
		max = get_max(max, solve(index + 1, 1) + MAP[1][index]);
		max = get_max(max, solve(index + 1, 2) + MAP[2][index]);
	}
	else if (pCheck == 1)
	{
		max = get_max(max, solve(index + 1, 0));
		max = get_max(max, solve(index + 1, 2) + MAP[2][index]);
	}
	else if (pCheck == 2)
	{
		max = get_max(max, solve(index + 1, 0));
		max = get_max(max, solve(index + 1, 1) + MAP[1][index]);
	}

	DP[index][pCheck] = max;
	return max;
}

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
				DP[j][i] = 0;
				DP[j][3] = 0;
#ifdef __D
				printf("%d ", MAP[i][j]);
#endif
			}
#ifdef __D
			printf("\n");
#endif
		}


		int ans = 0;
		ans = get_max(ans, solve(2, 0));
		ans = get_max(ans, solve(2, 1) + MAP[1][1]);
		ans = get_max(ans, solve(2, 2) + MAP[2][1]);

		printf("%d\n", ans);
	}

	return 0;
}
