
#include <stdlib.h>
#include <stdio.h>

#define MAX 200 


long long fibo(int n)
{
	if (n ==1 || n ==2)
		return 1;
	else
		return fibo(n-1) + fibo(n-2);
}

static long long memo[MAX];

long long fibo2(int n)
{
	if (memo[n] > 0)
		return memo[n];

	if (n ==1 || n ==2)
		return memo[n] = 1;
	else
		return memo[n] = (fibo2(n-1) + fibo2(n-2));
}

int main()
{
	int n,r;

	printf("input n:");
	scanf("%d", &n);
	printf("%lld\n", fibo2(n));

	return 0;
}
