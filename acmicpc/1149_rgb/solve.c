
#include <stdio.h>

#define 	MAX		1000
#define		COLOR_N		3	

int COLOR[MAX+1][COLOR_N+1];
int D[MAX+1][COLOR_N+1];
int N;
int main(void)
{ 
	int T, tc;
	int i, j, k, ans;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	//scanf("%d", &T);
	T = 1;
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (i=1; i<=N; i++)
		{
			for (j=1; j<=COLOR_N; j++)
			{
				scanf("%d", &COLOR[i][j]);
				D[i][j] = 0;
			}
		}

		for (i=1; i<=N; i++)
			D[1][i] = COLOR[1][i];

		int min;
		for (i=2; i<=N; i++)
		{
			for (j=1; j<=COLOR_N; j++)
			{
				D[i][j] = COLOR[i][j];
				min = 10000000;
				for (k=1; k<=COLOR_N; k++)
					if (k != j)
						if (min >= D[i-1][k])
							min = D[i-1][k];

				D[i][j] += min;
			}
		}

		min = D[N][1];
		for (j=2; j<=COLOR_N; j++)
		{
			if (min >= D[N][j])
				min = D[N][j];
		}

		printf("%d\n", min);
	}

	return 0;
}
