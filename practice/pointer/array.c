
#include <stdlib.h>
#include <stdio.h>


int main()
{
	int i, x[3] = {2,3,4};

	for (i=0; i<3; i++)
		printf("%d -> 0x%x\n", i, &x[i]);
		//printf("%d -> %d\n", i, &x[i]);

	for (i=0; i<3; i++)
		printf("&x[0] + %d -> 0x%x\n", i, &x[0] + i);
		//printf("&x[0] + %d -> %d\n", i, &x[0] + i);

	for (i=0; i<3; i++)
		printf("x + %d -> 0x%x\n", i, x + i);
		//printf("x + %d -> %d\n", i, x + i);

	return 0;
}
