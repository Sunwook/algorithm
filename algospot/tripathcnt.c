
#include <stdio.h>
#include <string.h>

#define T_MAX 	50
#define N_MAX	100	// 2 ~ 100

#define debug	printf

int triangle[N_MAX][N_MAX];
int cache[N_MAX][N_MAX];
int count_cache[N_MAX][N_MAX];
int t;
int n;

int result(int t)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			debug("%d ", triangle[i][j]);
		}
		debug("\n");
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int path(int y, int x)
{
	if (y == n-1)
		return triangle[y][x];

	if (cache[y][x] != -1)
		return cache[y][x];

	cache[y][x] = max(path(y+1, x), path(y+1, x+1)) + triangle[y][x];

	return cache[y][x];
}

int count(int y, int x)
{
	if (y == n-1)
		return 1;

	if (count_cache[y][x] != -1)
		return count_cache[y][x];

	if (path(y+1, x) > path(y+1, x+1))
		return count_cache[y][x] = count(y+1,x);
	else if (path(y+1, x) < path(y+1, x+1))
		return count_cache[y][x] = count(y+1,x+1);
	else
		return count_cache[y][x] = count(y+1,x) + count(y+1,x+1);
}

int main()
{
	int i, j, k, a;

	// Read from file
	freopen("tripathcnt.txt", "r", stdin);

	scanf("%d",&t);

	for (i=0; i<t; i++)
	{
		scanf("%d", &n);

		memset(triangle, 0, sizeof(triangle));
		memset(cache, -1, sizeof(cache));
		memset(count_cache, -1, sizeof(count_cache));
		for (j=0; j<n; j++)
			for (k=0; k<j+1; k++)
			{
				scanf("%d", &a);
				triangle[j][k] = a;
			}

		debug("%d\n",i);
		debug("%d\n",n);
		result(i);

		printf("result: %d\n",count(0,0));
	}

	return 0;
}

