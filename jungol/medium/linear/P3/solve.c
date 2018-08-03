// P3
// n개로 이루어진 정수 집합에서 원하는 수의 위치를 찾으시오.

#include <stdio.h>

#define 	__DEBUG 

#define	N_MAX	1000000

int N, K;
int i, j;

int D[N_MAX+1];

int solve(void)
{
	int ans = 0;
	int start = 1, end = N, mid = 0;


	while(1)
	{
		mid = (end + start) / 2;

		if (start >=end || mid == 0 || mid == N)
		{
#ifdef __DEBUG
			printf("\nend: %d\n", mid);
#endif
			return -1;
		}

		if (K == D[mid])
		{
#ifdef __DEBUG
			printf("\nanswer: %d\n", mid);
#endif
			return mid;
		}
		else if (K < D[mid])
		{
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}

#ifdef __DEBUG
		printf("\nstart:%d, mid: %d, end: %d\n", start, mid, end);
#endif
	}


	return -1;
}

int main(void)
{ 
	int tc, i, ans;

//#ifdef __DEBUG
	freopen("input.txt", "r", stdin);
//#endif

	setbuf(stdout, NULL);

	for (tc=1; tc<=2; tc++)
	{
#ifdef __DEBUG
		printf("#%d: ", tc);
#endif
		scanf("%d", &N);
#ifdef __DEBUG
		printf("\n%d\n", N);
#endif
		for (i=1; i<=N; i++)
		{
			scanf("%d", &D[i]);
#ifdef __DEBUG
			printf("%d ", D[i]);
#endif

		}
		scanf("%d", &K);
#ifdef __DEBUG
		printf("\n%d\n", K);
#endif
		ans = solve();

		printf("%d\n", ans);
	}

	return 0;
}
