
#include <stdio.h>
#include <string.h>

#define T_MAX 	50
#define N_MAX	500

#define debug	printf

int num[N_MAX];
int cache[N_MAX + 1];
int t;
int n;

int max(int a, int b)
{
	return a > b ? a : b;
}

#if 0
int lis(const vector<int>& A)
{
	if (A.empty()) return 0;
	int i, j, ret = 0;

	for (i=0; i<A.size(); i++)
	{
		vector<int> B;
		for (j=i+1; j<A.size(); j++)
			if (A[i] < A[j])
				B.push_back(A[j]);
			
		ret = max(ret, 1 + lis(B));
	}

	return ret;
}
#endif

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

int result(int t)
{
	int i;
	for (i=0; i<n; i++)
	{
		debug("%d ", num[i]);
	}

	debug("\n");
}

int main()
{
	int i, j, k, a;

	// Read from file
	freopen("lis_sample.txt", "r", stdin);

	scanf("%d",&t);

	for (i=0; i<t; i++)
	{
		scanf("%d", &n);

		memset(num, 0, sizeof(num));
		memset(cache, -1, sizeof(cache));

		for (j=0; j<n; j++)
		{
			scanf("%d", &a);
			num[j] = a;
		}

		//debug("%d\n",i);
		debug("%d\n",n);
		result(i);

		/*
		int ret = 0;
		for (j=0; j<n; j++)
			ret = max(ret, lis2(j));
		debug("lis: %d\n", ret);
		*/

		debug("lis: %d\n", lis3(-1) - 1);
	}

	return 0;
}

