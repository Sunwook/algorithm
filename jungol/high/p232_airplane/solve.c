
#include <stdio.h>

#define 	__D

#define 	MAX			100

int D[MAX+1][MAX+1];
int VISIT[MAX+1][MAX+1];
int H, W;
float th;
int ans;

int dp(int h, int w)
{
	if (h>H || w>W)
		return 0;

	printf("\n(%d,%d)", h, w);

	if (h == H && w == W)
	{
		D[h][w] = 1;
		return 1;
	}

	if (D[h][w])
		return D[h][w];

	int tmp1=0, tmp2=0;

	// h+1 , w
	/*
	if (w == 0)
	{
		if (h != H)
			tmp1 = dp(h+1,w);
	}
	else if (h == H)
		tmp1 = 0;
	else if (th <= (float)(h+1)/(float)w)
		tmp1 = dp(h+1,w);
	else
		tmp1 = 0;
		*/
	if (th <= (float)(h+1)/w)
		tmp1 = dp(h+1,w);

	//D[h][w] = dp(h+1, w) + dp(h, w+1);

	// h, w+1
	tmp2 = 0;
	if (h == 0)
	{
		/*
		if (w == 0)
			tmp2 = dp(h,w+1);
		else
			tmp2 = 0;
			*/
		tmp2 = 0;
	}
	else if (th <= (float)h/(float)(w+1))
		tmp2 = dp(h,w+1);

	D[h][w] = tmp1 + tmp2;

	return D[h][w];
}

int main(void)
{ 
	int T, tc;
	int i, j;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &H, &W);
		th = (float)H / (float)W;
#ifdef __D
		printf("#%d %d x %d,  th(%f)\n", tc, H, W, th);
#endif

		// ALGO
		ans = dp(0,0);

#ifdef __D
		printf("\nAnswer array:\n");
		for (i=0; i<=H; i++)
		{
			for (j=0; j<=W; j++)
				printf("%d ", D[i][j]);
			printf("\n");
		}
#endif

		// OUTPUT
#ifdef __D
		printf("\nans: ");
#endif
		printf("%d\n", ans);


	}

	return 0;
}
