
#include <stdio.h>
#include <string.h>

#define T_MAX 	50
#define N_MAX	100

#define debug	printf

int cache[N_MAX+1];
int mod = 1000000007;

int tiling(int n)
{
	if (n<=1) 
		return 1;

	if (cache[n] != -1)
		return cache[n];

	return cache[n] = (tiling(n-1) + tiling(n-2)) % mod;
}

int asym(int n)
{
	if (n % 2 == 1)
		//return tiling(n) - tiling((n-1) / 2);
		return (tiling(n) - tiling((n-1) / 2) + mod) % mod;
	else
		//return tiling(n) - tiling(n/2) - tiling((n-2)/2);
		return ((tiling(n) - tiling(n/2) + mod) % mod - tiling((n-2)/2) + mod) % mod;
}

int main()
{
	int i, j, t, n, a;

	// Read from file
	freopen("asymtiling.txt", "r", stdin);

	scanf("%d",&t);

	memset(cache, -1, sizeof(cache));

	for (i=0; i<t; i++)
	{
		scanf("%d", &n);
		debug("input: %d\n", n);

		printf("%d\n", asym(n));
	}

	return 0;
}

