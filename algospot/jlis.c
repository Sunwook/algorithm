
#include <stdio.h>
#include <string.h>
#include <limits>

#define T_MAX 	50
#define N_MAX	100

#define debug printf

int A[N_MAX];
int B[N_MAX];
int cache[N_MAX + 1][N_MAX + 1];
int t;
int n, m;
const long long NEGINF = std::numeric_limits<long long>::min();

int max(int a, int b)
{
	return a > b ? a : b;
}

/*
int lis2(int start)
{
	int i, ret = 1;

	if (start == n-1)
		return 1;

	if (cache[start] != -1)
		return cache[start];

	for (i=start+1; i<n; i++)
	{
		if (num[start] < num[i])
			ret = max(ret, lis2(i) + 1);
	}

	cache[start] = ret;

	return ret;
}

int lis3(int start)
{
	int i, ret = 1;

	if (start == n-1)
		return 1;

	if (cache[start+1] != -1)
		return cache[start+1];

	for (i=start+1; i<n; i++)
	{
		if (start == -1 || num[start] < num[i])
			ret = max(ret, lis3(i) + 1);
	}

	cache[start+1] = ret;

	return ret;
}
*/

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

int result(int t)
{
	int i;
	for (i=0; i<n; i++)
	{
		debug("%d ", A[i]);
	}

	debug("\n");
	for (i=0; i<m; i++)
	{
		debug("%d ", B[i]);
	}

	debug("\n");
}

int main()
{
	int i, j, k, a;

	// Read from file
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

		//debug("%d\n",i);
		debug("%d %d\n",n,m);
		result(i);

		/*
		int ret = 0;
		for (j=0; j<n; j++)
			ret = max(ret, lis2(j));
		debug("lis: %d\n", ret);
		*/

		//debug("lis: %d\n", lis3(-1) - 1);

		printf("jlis: %d\n", jlis(-1,-1) - 2);
	}

	return 0;
}

