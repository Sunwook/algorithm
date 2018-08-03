
#include <stdlib.h>
#include <stdio.h>

#define M	100
#define N	100

int map[M][N] = {0,};

int max(int m, int n)
{

	return 0;
}

int max_joy(int m, int n)
{
	if (m == 0 && n == 0)
		return map[0][0];

	if (n == 0)
		return max_joy(m-1,n) + map[m][n];

	if (m == 0)
		return max_joy(m,n-1) + map[m][n];

	return max(max_joy(m-1, n), max_joy(m, n-1)) + map[m][n];
}

int joy[M][N];

void calculate_joy(int m, int n)
{
	int i, j;

	joy[0][0] = map[0][0];

	for (i = 1; i < m; i++) 
		joy[i][0] = joy[i-1][0] + map[i][0];
	
	for (j = 1; j < n; j++) 
		joy[0][j] = joy[0][j-1] + map[0][j];

	for (i = 1; i < m; i++) 
		for (j = 1; j < n; j++) 
			joy[i][j] = max(joy[i-1][j], joy[i][j-1]) + map[i][j];

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
