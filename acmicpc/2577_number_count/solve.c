
#include <stdio.h>

//#define __D

int main(void)
{ 
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int a,b,c;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
#ifdef __D
	printf("a(%d), b(%d), c(%d)\n ", a, b, c);
#endif
	int sum = a*b*c;
#ifdef __D
	printf("sum: %d\n", sum);
#endif

	// #1
	/* 
	char str[15];
	sprintf(str, "%d", sum);
	int num_arr[10];
	for (int i=0; i<10; i++)
		num_arr[i] = 0;

	for (int i=0; i<15; i++)
	{
		if (str[i] == '\0')
			break;

		num_arr[str[i]-'0']++;
	}
	*/

	// #2
	int num_arr[10];
	for (int i=0; i<10; i++)
		num_arr[i] = 0;

	int remain;
	while (sum != 0)
	{
		remain = sum%10;
		sum /= 10;
		num_arr[remain]++;
	}


	for (int i=0; i<10; i++)
		printf("%d\n", num_arr[i]);

	return 0;
}
