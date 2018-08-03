
#include <stdio.h>

#define 	__D

#define 	P_MAX		11
#define 	F_MAX		10

int DP[P_MAX+1];
int DF[F_MAX+1];

int P,F;
int ans;

void search(int k, int dp[], int length)
{
	printf("k(%d), length(%d)\n", k, length);
	if (k == F)
	{
		printf("ans(%d), length(%d)\n", ans, length);
		if (length < ans)
			ans = length;

		return;
	}

	if (length > ans)
	{
		printf("pruning\n");
		return;
	}

	k++;
	int i, len;
	for (i=1; i<=P; i++)
	{
		if (dp[i] == 0)
		{
			dp[i] = 1;
			if (DF[k] > DP[i])
				len = DF[k] - DP[i];
			else
				len = DP[i] - DF[k];

			search(k, dp, length + len);
			dp[i] = 0;
		}
	}

}
int main(void)
{ 
	int T, tc, N;
	int i, j;

	//freopen("sample_input.txt", "r", stdin);
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &P, &F);
#ifdef __D
		printf("#%d P: %d F: %d\n", tc, P, F);
#endif
		for (i=1; i<=P; i++)
		{
			scanf("%d", &DP[i]);
#ifdef __D
			printf("%d ", DP[i]);
#endif
		}
#ifdef __D
		printf("\n");
#endif
		for (i=1; i<=F; i++)
		{
			scanf("%d", &DF[i]);
#ifdef __D
			printf("%d ", DF[i]);
#endif
		}
#ifdef __D
		printf("\n");
#endif

		// ALGO
		int dp[P_MAX+1] = {0,};

		ans = 987654321;
		search(0, dp, 0);



		// OUTPUT

#ifdef __D
		printf("\nans: ");
#endif
		printf("%d\n", ans);

		// Clear

	}

	return 0;
}
