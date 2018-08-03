// P1. 최대값(S)
// 9개의 서로 다른 자연수가 주어질 때, 이들 중 최댓값을 찾고 
// 그 값이 몇 번째 수 인지를 구하는 프로그램을 작성하시오

#include <stdio.h>

//#define 	__DEBUG 

#define N		9

int main(void)
{ 
	int i, num, max, index;

//#ifdef __DEBUG
	freopen("input.txt", "r", stdin);
//#endif

	setbuf(stdout, NULL);

	max = 0;
	index = 0;
	for (i=0; i<N; i++)
	{
		scanf("%d", &num);
#ifdef __DEBUG
		printf("%d\n", num);
#endif

		if (max < num)
		{
			max = num;
			index = i+1;
		}
	}

	printf("-------------------\n");
	printf("%d\n", max);
	printf("%d\n", index);

	return 0;
}
