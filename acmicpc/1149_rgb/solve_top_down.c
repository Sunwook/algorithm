
// https://www.acmicpc.net/problem/1149

#include <stdio.h>

#define 	__D

#define 	MAX		1000
#define		COLOR_N		3	

int COLOR[MAX+1][COLOR_N+1];
int MEMO[MAX+1][COLOR_N+1];

int ans;
int N;

int memo(int i, int pColor)
{
	if (i == N+1)
		return 0;
	
	if (MEMO[i][pColor] != 0)
		return MEMO[i][pColor];

	int k, tmp, min = 100000000;
	for (k=1; k<=N; k++)
	{
		if (k != pColor)
		{
#ifdef __D
			printf("prev is %d, selecting a current color (%d)\n", pColor, k);
#endif
			tmp = memo(i+1, k) + COLOR[i][k];
		}

		if (tmp <= min)
			min = tmp;
	}

#ifdef __D
	printf("MEMO [%d][%d] = %d\n", i, pColor, min);
#endif

	MEMO[i][pColor] = min;

	return min;
}

int main(void)
{ 
	int T, tc;
	int i, j;

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
				MEMO[i][j] = 0;
			}
#ifdef __D
			printf("\n");
#endif
		}

		// ALGO

		/* Memoization
		 */
		/*
		for (i=1; i<=COLOR_N; i++)
		{
			MEMO[1][i] = COLOR[1][i];
		}
		*/

		ans = 10000000;
		int tmp;
		for (i=1; i<=COLOR_N; i++)
		{
			tmp = COLOR[1][i] + memo(2, i);
			if (ans >= tmp)
				ans = tmp;
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
