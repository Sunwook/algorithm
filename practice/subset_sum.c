
#include <stdlib.h>
#include <stdio.h>

#define M	100
#define N	100

int map[M][N] = {0,};

int max(int m, int n)
{

	return 0;
}

int c[M][N];

int subset_sum(int s[], int n, int m)
{
	if (n == 0)
		if (m == 0)
			return 1;
		else
			return 0;

	return max(subset_sum(s, n-1, m-s[n-1]), subset_sum(s, n-1, m));

}

void calculate_subset_sum(int s[], int n, int m)
{
	int i, j;

	for (i=0; i<=n; i++)
		c[i][0] = 1;

	for (i=1; i<=m; i++)
		c[0][i] = 0;
}

int main()
{
	int m, n, i, j;

	scanf("%d %d", &m, &n);

	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			scanf("%d",&map[i][j]);


	printf("%d", max_joy(m-1, n-1));

	return 0;
}
