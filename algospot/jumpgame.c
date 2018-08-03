
#include <stdio.h>
#include <string.h>

#define T_MAX 	50
#define N_MAX	100	// 2 ~ 100

//#define debug	printf
#define debug

int board[N_MAX][N_MAX];
int cache[N_MAX][N_MAX];
int t;
int n;

int jump(int y, int x)
{
	int value = 0;

	if (y > n-1 || x > n-1)
		return 0;

	if (y == n-1 && x == n-1)
		return 1;

	if (cache[y][x] != -1)
		return cache[y][x];

	value = board[y][x];

	//return (cache[y][x+value] = jump(y, x + value)) || (cache[y+value][x] = jump(y + value, x));
	return cache[y][x] = (jump(y, x + value)) || jump(y + value, x);
}

int calculate(int t)
{
	return jump(0,0);

}

int result(int t)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			debug("%d ", board[i][j]);
		}
		debug("\n");
	}
}

int main()
{
	int i, j, k, a;

	// Read from file
	freopen("jumpgame_sample.txt", "r", stdin);

	scanf("%d",&t);

	for (i=0; i<t; i++)
	{
		scanf("%d", &n);

		memset(board, -1, sizeof(board));
		memset(cache, -1, sizeof(cache));
		for (j=0; j<n; j++)
			for (k=0; k<n; k++)
			{
				scanf("%d", &a);
				board[j][k] = a;
			}

		debug("%d\n",i);
		debug("%d\n",n);
		result(i);

		if (calculate(i))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

