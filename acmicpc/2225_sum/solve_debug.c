
#include <stdio.h>

int DP[201][201];
int solve(int n, int k)
{
	printf("[%d,%d]\n", n, k);

	if (DP[n][k] != -1)
	{
		printf("checked (%d,%d) = %d\n", n, k, DP[n][k]);
		return DP[n][k];
	}
	if (n == 0)
	{
		DP[n][k] = 1;
		printf("  PRE (%d,%d) = %d\n", n, k, DP[n][k]);
		return 1;
	}
	if (n == 1)
	{
		DP[n][k] = k;
		printf("  PRE (%d,%d) = %d\n", n, k, DP[n][k]);
		return k;
	}
	if (k == 0)
	{
		DP[n][k] = 0;
		printf("  PRE (%d,%d) = %d\n", n, k, DP[n][k]);
		return 0;
	}
	if (k == 1)
	{
		DP[n][k] = 1;
		printf("  PRE (%d,%d) = %d\n", n, k, DP[n][k]);
		return 1;
	}

	int i,ans=0;
	for (i=0; i<=n; i++)
		ans += solve(n-i,k-1);
	DP[n][k] = ans;
	printf(" DONE (%d,%d) = %d\n", n, k, DP[n][k]);
	return DP[n][k];
}

int main(void)
{ 
	int N, K;
	scanf("%d %d", &N, &K);

	int i,j;
	for (i=0; i<=N; i++)
		for (j=0; j<=K; j++)
			DP[i][j] = -1;

	DP[0][0] = 1;

	printf("%d\n", solve(N,K)%1000000000); 

	return 0;
}
