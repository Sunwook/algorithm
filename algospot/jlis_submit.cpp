#include <stdio.h>
#include <string.h>
#include <limits>

#define N_MAX   100

int A[N_MAX];
int B[N_MAX];
int cache[N_MAX + 1][N_MAX + 1]; 
int n, m;

const long long NEGINF = std::numeric_limits<long long>::min();

int max(int a, int b)
{
	return a > b ? a : b;
}
int jlis(int indexA, int indexB)
{
	int nextA, nextB;
	int& ret = cache[indexA+1][indexB+1];
	if (ret != -1)
		return ret;

	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a,b);

	for (nextA = indexA + 1; nextA<n; nextA++)
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);

	for (nextB = indexB + 1; nextB<m; nextB++)
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);

	return ret;
}
int main()
{
	int i, j, t, a;

	freopen("jlis_sample.txt", "r", stdin);
	scanf("%d",&t);

	for (i=0; i<t; i++)
	{
		scanf("%d %d", &n, &m);

		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(cache, -1, sizeof(cache));

		for (j=0; j<n; j++)
		{
			scanf("%d", &a);
			A[j] = a;
		}

		for (j=0; j<m; j++)
		{
			scanf("%d", &a);
			B[j] = a;
		}

		printf("%d\n", jlis(-1,-1) - 2);
	}

	return 0;
}
