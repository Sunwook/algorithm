
#include <stdlib.h>
#include <stdio.h>

int add(int a, int b)
{
	return a+b;
}

int sub(int a, int b)
{
	return a-b;
}

int (*func)(int a, int b);

int main()
{
	func = add;
	printf("add 1+4 = %d\n", func(1,4));

	func = sub;
	printf("sub 1-4 = %d\n", func(1,4));

	return 0;
}
