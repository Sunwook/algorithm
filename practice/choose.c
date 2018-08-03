
#include <stdlib.h>
#include <stdio.h>

static int i = 0;
long long choose(int n, int r)
{
	i++;

	if (r==0 || n==r)
		return 1;

	return choose(n-1, r-1) + choose(n-1, r);
}

#define MAX 200 

static int j = 0;
long long choose2(int n, int r)
{
	static long long memo[MAX][MAX];

	j++;

	if (memo[n][r] > 0)
		return memo[n][r];
	
	if (r==0 || n==r)
		return memo[n][r] = 1;

	return memo[n][r] = choose2(n-1, r-1) + choose2(n-1, r);
}

int main()
{
	int n,r;

	printf("input n, r:");
	scanf("%d %d", &n, &r);
	printf("%lld\n", choose(n,r));
	printf("call count : %d\n", i);

	return 0;
}
