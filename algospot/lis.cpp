
#include <stdio.h>
#include <string.h>

#include <vector>
using namespace std;

#define T_MAX 	50
#define N_MAX	500

#define debug	printf

int num[N_MAX];
int t;
int n;

int max(int a, int b)
{
	return a > b ? a : b;
}

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
		vector<int> A;

		for (j=0; j<n; j++)
		{
			scanf("%d", &a);
			num[j] = a;
			A.push_back(a);
		}

		//debug("%d\n",i);
		debug("%d\n",n);
		result(i);

		debug("lis: %d\n", lis(A));

	}

	return 0;
}

