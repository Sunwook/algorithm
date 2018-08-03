
#include <stdio.h>
#include <math.h>

#define 	get_min(a,b)	(a > b ? b : a)
#define     get_dist(ax, ay, bx, by)    ((ax-bx)*(ax-bx) + (ay-by)*(ay-by))

int P[17][3];
double DIST[17][17];
//double DP[17][65536];
double MEMO[65536];
int N;
double ans;

double solve(int check)
{
	if (MEMO[check] > -0.5)
		return MEMO[check];

	if (check == 65534)
		return MEMO[check] = 0;


	int i,j,bit1, bit2;
	double min=2000000000.0;
	for (i=1; i<=N; i++)
	{
		bit1 = 1 << (i-1);
		if (!(check & bit1)) 
		{
			for (j=i+1; j<=N; j++)
			{
				bit2 = 1 << (j-1);
				if (!(check & bit2)) 
				{
					//min = get_min(min, solve(k-2, (check | bit1 | bit2)) + sqrt(get_dist(P[i][1], P[i][2], P[j][1], P[j][2])));
					min = get_min(min, solve(check | bit1 | bit2) + DIST[i][j]);
				}
			}
			break;
		}
	}

	MEMO[check] = min;

	return MEMO[check];
}

int main(void)
{ 
	int tc = 0;
	int i, j, max;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);
	char student[20+1];
	while (1) 
	{
		tc++;
		scanf("%d", &N);
		if (N == 0)
			break;
		N *= 2;
		for (i=1; i<=N; i++)
		{
			scanf("%s %d %d", &student[0], &P[i][1], &P[i][2]);
			max = N*N;
			//for (j=0; j<=max; j++)
				//DP[i][j] = -1;
		}
		for (i=1; i<=N; i++)
			for (j=1; j<=N; j++)
			{
				DIST[i][j] = sqrt(get_dist(P[i][1],P[i][2],P[j][1],P[j][2]));
			}

		ans = solve(0);
		memset(MEMO,-1,sizeof(MEMO));
		printf("Case %d: %.2f\n", tc, ans);
	}

	return 0;
}
