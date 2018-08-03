
#include <stdio.h>
#include <string.h>

#define T_MAX 	50
#define N_MAX	100

#define debug	printf

int board[N_MAX][N_MAX];
int t;
int n;

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
		for (j=0; j<n; j++)
			for (k=0; k<n; k++)
			{
				scanf("%d", &a);
				board[j][k] = a;
			}

		debug("%d\n",i);
		debug("%d\n",n);
		result(i);
	}

	return 0;
}

