
#include <stdio.h>
#include <string.h>

int friends[10][10];
int n;

int count(int take[10])
{
	int i=0, ret=0;
	int firstRemain = -1;

	for (i=0; i<n; i++)
		if (!take[i])
		{
			firstRemain = i;
			break;
		}

	if (firstRemain == -1)
		return 1;

	for (i=firstRemain+1; i<n; i++)
		if (!take[i] && friends[firstRemain][i])
		{
			take[i] = take[firstRemain] = 1;
			ret += count(take);
			take[i] = take[firstRemain] = 0;
		}

	return ret;
}

int result(int i)
{
	int take[10] = {0,};
	int r = count(take);
	printf("%d\n", r);
}

int main()
{
	int t, i, j, m, a, b;
	scanf("%d",&t);

	for (i=0; i<t; i++)
	{
		scanf("%d", &n);
		scanf("%d", &m);

		memset(friends, 0, 100);

		for (j=0; j<m; j++)
		{
			scanf("%d", &a);
			scanf("%d", &b);
			friends[a][b] = friends[b][a] = 1;
		}

		result(i);
	}

	return 0;
}

