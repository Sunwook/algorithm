#include <stdio.h>

#define 	__D

#define 	MAX		100

int D[MAX+1][MAX+1];

int N, M;
int ans;
int count;

int dh[4] = {0, 0, 1, -1};
int dw[4] = {1, -1, 0, 0};

void print(void)
{
	int i,j;
	printf("\nData:\n");
	for (i=1; i<=N; i++)
	{
		for (j=1; j<=M; j++)
			printf("%d ", D[i][j]);
		printf("\n");
	}

	printf("\n");

}
void set_boundary(int h, int w)
{
	D[h][w] = 2;

	int i;
	int tmp_h, tmp_w;
	for (i=0; i<4; i++)
	{
		tmp_h = h + dh[i];
		tmp_w = w + dw[i];
		if (tmp_h >= 1 && tmp_w >= 1 && tmp_h <= N && tmp_w <= M)
			if (D[tmp_h][tmp_w] == 0)
			{
				set_boundary(tmp_h, tmp_w);
			}
	}
}

void update(void)
{
	int i,j;
	for (i=1; i<=N; i++)
		for (j=1; j<=M; j++)
		{
			if (D[i][j] == 2)
				D[i][j] = 0;
			else if (D[i][j] == 4)
				D[i][j] = 0;
			else if (D[i][j] == 3)
			{
				D[i][j] = 1;
				++count;
			}
		}
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
		scanf("%d %d", &N, &M);
#ifdef __D
		printf("#%d: N(%d) x M(%d)\n", tc, N, M);
		for (i=1; i<=N; i++)
		{
			for (j=1; j<=M; j++)
			{
				scanf("%d", &D[i][j]);
				printf("%d ", D[i][j]);
			}

			printf("\n");
		}
#endif

		// ALGO
		ans = 0;

		while(1)
		{
			++ans;

			count = 0;
			set_boundary(1,1);

			//print();
			//if (!count)
			//	break;

			// Check
			count = 0;
			for (i=1; i<=N; i++)
				for (j=1; j<=M; j++)
					if (D[i][j] == 1)
					{
						int k, check = 0;
						int tmp_h, tmp_w;
						for (k=0; k<4; k++)
						{
							tmp_h = i + dh[k];
							tmp_w = j + dw[k];
							if (D[tmp_h][tmp_w] == 2)
								++check;
						}

						if (check >= 2)
							D[i][j] = 4;
						else
							D[i][j] = 3;
					}

			update();

#ifdef __D
			print();
#endif
			if (!count)
				break;
		}

		
		// OUTPUT

#ifdef __D
		printf("\nanswer: ");
#endif
		printf("%d\n", ans);

#ifdef __D
		printf("------------------\n\n");
#endif

		// Clear

	}


	return 0;
}

