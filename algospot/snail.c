
#include <stdio.h>
#include <string.h>

#define T_MAX 	50
#define N_MAX	1000
#define M_MAX	1000

#define debug	printf

double cache[N_MAX+1][2*M_MAX+1];

int day,n;

double climb(int days, int climbed)
{
	//debug("climb %d, %d\n", days, climbed);

	if (days == day) 
		return climbed >= n ? 1.0 : 0;

	if (cache[days][climbed] != -1)
		return cache[days][climbed];

	return cache[days][climbed] = 0.75 * climb(days+1, climbed+1) + 0.25 * climb(days+1, climbed+2);
}

int main()
{
	int i, t;

	// Read from file
	freopen("snail.txt", "r", stdin);

	scanf("%d",&t);

	int j, k;
	for (i=0; i<t; i++)
	//for (i=0; i<1; i++)
	{
		//memset(cache, 0, sizeof(cache));
		for (j=0; j<N_MAX; j++)
			for (k=0; k<2*N_MAX; k++)
				cache[j][k] = -1;

		scanf("%d %d", &n, &day);
		debug("input: %d %d\n", n, day);

		printf("%f\n", climb(0, 0));
	}

	return 0;
}

