
#include <stdio.h>

char name[255];

int main()
{
	int i,n;
	scanf("%d",&n);

	for (i=0; i<n; i++)
	{
		scanf("%s", name);
		printf("Hello, %s!\n", name);
	}

	return 0;
}

