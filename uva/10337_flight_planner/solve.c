
#include <stdio.h>

#define __D

#define 	MAX		100000

#define get_min(a,b)	( (a) > (b) ? (b) : (a) )

int MAP[1001][11];
int DP[1001][11];
int N;

int search(int height, int  step)
{
#ifdef __D
	printf("[Step %d][height %d]\n", step, height);
#endif
	if (step == N+1)
	{
#ifdef __D
		printf("[Step %d][height %d] done!!\n", step, height);
#endif
		return 0;
	}

	if (DP[height][step] != 0)
		return DP[height][step];


	// STILL
	int value = search(height, step + 1) + 30 - MAP[height][step];

	// UP
	if (height - 1 > 0)
		value = get_min(value, search(height-1, step + 1) + 60 - MAP[height][step]);
	// DOWN
	if (height + 1 < 11)
		value = get_min(value, search(height+1, step + 1) + 20 - MAP[height][step]);

#ifdef __D
	printf("[Step %d][height %d] value = %d\n", step, height, value);
#endif
	DP[height][step] = value;

	return value;
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
		N /= 100;
#ifdef __D
		printf("#%d %d\n", tc, N);
#endif
		for (i=1; i<=10; i++)
		{
			for (j=1; j<=N; j++)
			{
				scanf("%d", &MAP[i][j]);
#ifdef __D
				printf("%d ", MAP[i][j]);
#endif

			}
#ifdef __D
			printf("\n");
#endif
		}

		printf("%d\n", search(10,1));

		// Clear
		for (i=1; i<=10; i++)
			for (j=1; j<=N; j++)
				DP[i][j] = 0;
	}

	return 0;
}
