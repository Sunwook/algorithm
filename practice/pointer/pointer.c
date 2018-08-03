
#include <stdlib.h>
#include <stdio.h>


int main()
{
	int x = 999, *p;

	p = &x;

	printf("value x: %d, address: %d, 0x%x\n", x, &x, &x);
	printf("value p: %d, address: %d, 0x%x\n", p, &p, &p);
	printf("value *p: %d, address: %d, 0x%x\n", *p, p, p);

	return 0;
}
