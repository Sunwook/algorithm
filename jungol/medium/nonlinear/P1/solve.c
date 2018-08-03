// P1
// 두더지굴 (DFS)

#include <stdio.h>

#define 	__DEBUG 

#define	N_MAX	30

int N;
int i, j;

int D[N_MAX+1][N_MAX+1];
int A[N_MAX+1];

int answer;
int count;

void dfs(int y, int x)
{
	D[y][x] = 2;
	count++;

	if (y > 1 && D[y-1][x] == 1)
		dfs(y-1, x);

	if (y < N && D[y+1][x] == 1)
		dfs(y+1, x);

	if (x > 1 && D[y][x-1] == 1)
		dfs(y, x-1);

	if (x < N && D[y][x+1] == 1)
		dfs(y, x+1);

	return;
}

void solve(void)
{
	answer = 0;
	count = 0;

	for (i=1; i<=N; i++)
	{
		for (j=1; j<=N; j++)
		{
			if (D[i][j] == 1)
			{
#ifdef __DEBUG
	printf("current i:%d, j:%d\n", i, j);
#endif
				count = 0;
				dfs(i,j);
				++answer;
#ifdef __DEBUG
				printf("candidate: %d\n", count);
				printf("answer: %d\n", answer);
#endif
			}
			else
				continue;
		}
	}
}

void print_result(void)
{

}

int main(void)
{ 
//#ifdef __DEBUG
	freopen("input.txt", "r", stdin);
//#endif

	setbuf(stdout, NULL);

	scanf("%d", &N);
#ifdef __DEBUG
	printf("%d\n", N);
#endif
	for (i=1; i<=N; i++)
	{
		for (j=1; j<=N; j++)
		{
			scanf("%d", &D[i][j]);
#ifdef __DEBUG
			printf("%d ", D[i][j]);
#endif
		}
#ifdef __DEBUG
		printf("\n");
#endif
	}

	solve();

	print_result();

	memset(D, 0, sizeof(D));

	return 0;
}
