
#include <stdio.h>

#define 	MAX		10000


int get_d(int n)
{
	int ret = n;
	int next = n;
	int current = n;
	int mod = 0;

	while(1)
	{
		next = current / 10;
		mod = current % 10;
		if (next < 10)
		{
			ret += next + mod;
			break;
		}

		ret += mod;

		current = next;
	}

	return ret;
}

int main(void)
{ 
	int CHK[2*MAX];
	int num;

	for (int i=1; i<=MAX; i++)
	{
		num = get_d(i);
		CHK[num] = 1;
		//printf("%d\n", num);
	}

	//printf("-------------------");

	for (int i=1; i<=MAX; i++)
		if (CHK[i] == 0)
			printf("%d\n", i);

	return 0;
}
