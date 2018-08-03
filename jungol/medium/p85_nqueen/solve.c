
#include <stdio.h>
#include <time.h>

#define 	__D

#define 	MAX		8

int D[MAX+1][MAX+1];
int CHK[MAX+1][MAX+1];
int CHK_COL[MAX+1];

int N;
int ans;

/*
void check_diagnal(int h, int w, int chk[][])
{

	return 1;
}
*/

void print_check(void)
{
	int i,j;
	printf("- DATA\n");
	for (i=1; i<=N; i++)
	{
		for (j=1; j<=N; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}
	printf("\n-- CHECK\n");

	for (i=1; i<=N; i++)
	{
		for (j=1; j<=N; j++)
			printf("%d ", CHK[i][j]);
		printf("\n");
	}
	printf("\n");

}

int check_diagnal(int row, int col)
{
	int i;
	for (i=0; i<row; i++)
	{
		if (CHK[row-i][col-i])
			return 0;

		if (CHK[row-i][col+i])
			return 0;
	}

	return 1;
}

void set_diagnal(int row, int col)
{
	int i;
	CHK[row][col] = 1;
	for (i=1; i<N; i++)
	{
		if (row+i <= N)
		{
			CHK[row+i][]
			CHK[row+i][]
		}

		if (row-i > 0)
		{
			CHK[row-i][]
			CHK[row-i][]
		}

		if (col - i > 0)
		{
			CHK[row-i][col-i] = 1;
			CHK[row+i][col-i] = 1;
		}
	}

	int count = 1;
	for (i=row+1; i<=N; i++)
	{
		if (col + count <= N)
		{
			CHK[i][col+count] = 1;
			CHK[i][col+count] = 1;
		}

		count++;
	}
}

void unset_diagnal(int row, int col)
{
	int i;
	for (i=0; i<row; i++)
	{
		CHK[row-i][col-i] = 0;
		CHK[row-i][col+i] = 0;
	}

	for (i=row+1; i<=N; i++)
	{
		CHK[i][col-i] = 0;
		CHK[i][col+i] = 0;
	}
}

//int bt(int col[], int chk *[], int k, int n)
int bt(int k, int n)
{
	if (k == n + 1)
	{
		++ans;
		return;
	}

	print_check();

	int i;
	k++;
	for (i=1; i<=N; i++)
	{
		if (CHK_COL[i] == 0 && check_diagnal(k, i))
		//if (CHK_COL[i] == 0)
		{
			D[k][i] = 1;
			CHK_COL[i] = 1;
			set_diagnal(k, i);
			//bt(col, chk, k, n);
			bt(k, n);
			D[k][i] = 0;
			CHK_COL[i] = 0;
			unset_diagnal(k, i);
		}
	}


	return 0;
}

int main(void)
{ 
	int tc, T;
	int i,j;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
#ifdef __D
		printf("#%d: N(%d)\n", tc, N);
#endif

		// ALGO
		ans = 0;
		bt(0, N);


		
		// OUTPUT

#ifdef __D
		printf("\nanswer: ");
#endif
		printf("%d\n", ans);

#ifdef __D
		printf("------------------\n\n");
#endif

		// Clear
		for (i=1; i<=N; i++)
		{
			CHK_COL[i] = 0;
			for (j=1; j<=N; j++)
			{
				CHK[i][j] = 0;
			}
		}

	}


	return 0;
}

