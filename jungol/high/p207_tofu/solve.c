
#include <stdio.h>

#define 	__D

#define 	MAX		11

char D[MAX + 2][MAX + 2];
int CHECK[MAX + 2][MAX + 2];
int CACHE[MAX + 2][MAX + 2][4096];

int PRICE[27][27]= { {100,70,40}, {70,50,30}, {40,30,20}};

int N;
int ans;

void print_data(int count)
{
	int i,j;

	printf("\n");
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
			printf("%c", D[i][j]);

		printf("\n");
	}
	printf("count: %d\n", count);
}

int safe_check(int h, int w)
{
	if (h < 0 || w < 0 || h >= N || w >= N)
		return 0;

	return 1;
}

int get_check_bit(int h, int w)
{
	int i;
	int bit = 0;
	int count = 0;
	if (CHECK[h][w])
		bit = 1;

	if (w < N)
		for (i=w+1; i<N; i++)
		{
			++count;
			if (CHECK[h][i])
				bit |= (1 << count);
		}

	if (h < N )
	{
		for (i=0; i<=w; i++)
		{
			++count;
			if (CHECK[h+1][i])
				bit |= (1 << count);
		}
	}

	printf("\nbit check (%d,%d) bit(%d)", h, w, bit);

	return bit;
}

int get_value(char a, char b)
{
	return PRICE[a-'A'][b-'A'];
}

int solve(int h, int w, int count)
{
	int i,j;
#ifdef __D
	//printf("\nCurrent Pos (%d,%d), count(%d)", h, w, count);
#endif

	if (w == N)
	{
		h += 1;
		w = 0;
	}

	if (h == N)
	{
		//printf("\n------- END !!!, ans(%d), count(%d)\n", ans, count);

		if (ans < count)
			ans = count;

		return ans;
	}

	int check_bit = get_check_bit(h, w);

	if (CACHE[h][w][check_bit])
		return CACHE[h][w][check_bit];

	int tmp = 0;
	int max = 0;

	// Possibly check
	if (!CHECK[h][w])
	{
		int diff;

		CHECK[h][w] = 1;

		// 1. 1x2
		if (safe_check(h,w+1) && !CHECK[h][w+1])
		{
			CHECK[h][w+1] = 1;
			diff = get_value(D[h][w], D[h][w+1]);
			max = solve(h, w+1, count + diff);

			CHECK[h][w+1] = 0;
		}

		// 2. 2x1
		if (safe_check(h+1,w) && !CHECK[h+1][w])
		{
			CHECK[h+1][w] = 1;
			diff = get_value (D[h][w], D[h+1][w]);
			tmp = solve(h, w+1, count + diff);

			CHECK[h+1][w] = 0;
		}
		
		CHECK[h][w] = 0;

		if (max < tmp)
			max = tmp;
	}

	tmp = solve(h, w+1, count);
	if (max < tmp)
		max = tmp;

	CACHE[h][w][check_bit] = max;

	return max;

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
//#ifdef __D
		printf("#%d: %d x %d\n", tc, N, N);
//#endif
		for (i=0; i<N; i++)
		{
			scanf("%s", &D[i]);
#ifdef __D
			printf("%s\n", D[i]);
#endif
		}


		// ALGO
		ans = 0;
		ans = solve(0, 0, 0);
						
		
		// OUTPUT

#ifdef __D
		printf("\nanswer: ");
#endif
		printf("%d\n", ans);

#ifdef __D
		printf("------------------\n\n");
#endif

		// Clear
		int k;
		for (i=0; i<=N+1; i++)
			for (j=0; j<=N+1; j++)
			{
				D[i][j] = 0;
				CHECK[i][j] = 0;
				for (k=0; k<4096; k++)
					CACHE[i][j][k] = 0;
			}
	}


	return 0;
}

