
#include <stdio.h>

int DP[201][201];
int solve(int n, int k)
{
	if (DP[n][k] != -1)
		return DP[n][k];
	if (n == 0)
		return 1;
	if (n == 1)
		return k;
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;

	int i,ans=0;
	for (i=0; i<=n; i++)
	{
		ans += solve(n-i,k-1);
		ans %= 1000000000;
	}
	DP[n][k] = ans;
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

	printf("%d\n", solve(N,K)); 

	return 0;
}
