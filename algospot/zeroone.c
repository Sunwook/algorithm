#include <stdio.h>
#include <string.h>

#define DATA_MAX    1000000
#define INPUT_MAX   100000

char data[DATA_MAX] = {0,};
int sum_data[DATA_MAX] = {0,};

void calculate(int min, int max)
{
	int i=0, num0=0, num1=0, start=0, diff=0;

	if (min == max)
	{
		printf("Yes\n");
		return;
	}

	if (min > max)
	{
		int tmp;
		tmp = min;
		min = max;
		max = tmp;
	}

	if (data[min] == '1')
	{
		start = 1;
		num1++;
	}
	else
		num0++;

	if (min == 0)
		diff = sum_data[max];
	else
		diff = sum_data[max] - sum_data[min-1];

	int value = max - min + 1;

	if (diff == value || diff == 0)
		printf("Yes\n");
	else
		printf("No\n");
}

int main()
{
	int i = 0, len=0, input_count=0, min=0,max=0;

	scanf("%s", data);
	scanf("%d", &input_count);

	len = strlen(data);

	int num = 0;
	sum_data[0] = data[0] - '0';
	for (i=1; i<len; i++)
	{
		num = data[i] - '0';
		sum_data[i] = sum_data[i-1] + num;
	}

	for (i=0; i<input_count; i++)
	{
		scanf("%d %d", &min, &max);
		calculate(min, max);
	}

	return 0;
}
