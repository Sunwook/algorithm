
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INPUT_MAX   50
#define ITEM_STRING_MAX 20

#define N_MAX       100
#define W_MAX       1000

#define VOL_MAX     1000
#define FAV_MAX     1000

#define log


int item_count = 0;
int weight = 0;

char item[N_MAX][ITEM_STRING_MAX];
char list[N_MAX][ITEM_STRING_MAX];

int volume[VOL_MAX];
int need[FAV_MAX];

int cache[N_MAX][VOL_MAX + 1]; 

int count = 0;

int max(int a, int b)
{
	return a >= b ? a : b;
}

/*
int get_max_need(int i, int remain)
{
	int ret = 0;

	if (i == item_count)
	{   
		log("search done\n");
		return 0;
	}   

	if (cache[i][remain] != -1) 
		return cache[i][remain];

	ret = get_max_need(i+1, remain);

	if (volume[i] <= remain)
		return max (ret, get_max_need(i+1, remain - volume[i]) + need[i]);

	cache[i][remain] = ret;

	log("index %d, remain %d, need: %d\n", i, remain, ret);

	return ret;
}
*/

int get_max_need(int item, int capacity) {
	if(item == item_count) return 0;

	int& ret = cache[item][capacity];
	if(ret != -1) return ret;

	ret = get_max_need(item+1, capacity);
	if(capacity >= volume[item])
		ret = max(ret, get_max_need(item+1, capacity - volume[item]) + need[item]);
	return ret;
}

void get_list(int i, int remain)
{
	if (i == item_count)
		return;

	if (get_max_need(i, remain) == get_max_need(i+1, remain))
		get_list(i+1, remain);
	else
	{
		strncpy(list[count++], item[i], ITEM_STRING_MAX);
		//printf("%s\n", item[i]);
		get_list(i+1, remain - volume[i]);
	}
}

void get_max(void)
{
	int i, j;

	printf("%d ", get_max_need(0, weight));

	count = 0;

	get_list(0, weight);

	printf("%d\n", count);

	for (i=0; i<count; i++)
		printf("%s\n", list[i]);

	return;
}

int main()
{
	int i, j;
	int len = 0;
	int input_count = 0;

	// Read from file
	freopen("packing_sample.txt", "r", stdin);

	scanf("%d", &input_count);
	log("%d\n", input_count);

	for (i=0; i<input_count; i++)
	{
		scanf("%d %d", &item_count, &weight);
		log("%d %d\n", item_count, weight);

		memset(item, 0, sizeof(item));
		memset(list, 0, sizeof(list));
		memset(volume, 0, sizeof(volume));
		memset(need, 0, sizeof(need));
		memset(cache, -1, sizeof(cache));

		for (j=0; j<item_count; j++)
		{
			scanf("%s", item[j]);
			scanf("%d %d", &volume[j], &need[j]);

			log("%s ", item[j]);
			log("%d %d\n", volume[j], need[j]);
		}

		get_max();
	}

	return 0;
}

