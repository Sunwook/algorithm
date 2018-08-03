
#include <stdio.h>

#define 	__D

#define		N_MAX	1000
#define		W_MAX	15

int N,W;
int D[W_MAX+1][2];
int ans;

int main(void)
{ 
	int T, tc, N;
	int i, j;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &W);
#ifdef __D
		printf("#%d N: %d W: %d\n", tc, N, W);
#endif
		for (i=1; i<=W; i++)
		{
			scanf("%d %d", &D[i][0], &D[i][1]);
#ifdef __D
			printf("%d %d\n", D[i][0], D[i][1]);
#endif
		}

		// ALGO

		// OUTPUT

#ifdef __D
		printf("\nans: ");
#endif
		printf("%d\n", ans);

		// Clear

	}

	return 0;
}
