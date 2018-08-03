
#include <stdio.h>

int main(void)
{ 
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int count = 0;
	char str[1000000] = {0};
	while (1)
	{
		str[0] = '\0';
		scanf("%s", &str[0]);
		if (str[0] == '\0')
			break;

		//printf("%s\n", str);
		++count;
	}

	printf("%d\n", count);

	return 0;
}
