
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// C++
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

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

string name[100];

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

// 캐리어에 남은 용량이 capacity 일 때, item 이후의 물건들을 담아 얻을   수 있는 최대
// 절박도의 합을 반환한다
int get_max_need(int i, int capacity) {
	// 기저 사례: 더 담을 물건이 없을 때
	if(i == item_count) return 0;

	// 메모이제이션
	int& ret = cache[i][capacity];
	if(ret != -1) return ret;

	// 이 물건을 담지 않을 경우
	ret = get_max_need(i+1, capacity);
	// 이 물건을 담을 경우
	if(capacity >= volume[i])
		ret = max(ret, get_max_need(i+1, capacity - volume[i]) + need[i]);
	return ret;
}

/*
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
*/

// pack(capacity, item) 이 선택한 물건들의 목록을 picked 에 저장한다
void reconstruct(int capacity, int i, vector<string>& picked) {
	if(i == item_count) return;
	if(get_max_need(i, capacity) == get_max_need(i+1, capacity))
		reconstruct(capacity, i+1, picked);
	else {
		//picked.push_back(name[i]);
		picked.push_back(item[i]);
		//printf("%s\n", item[i]);
		reconstruct(capacity - volume[i], i+1, picked);
	}   
}

/*
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
*/

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

		//get_max();

		// C++
		vector<string> picked;
		reconstruct(weight, 0, picked);
		printf("%d %d\n", get_max_need(0, weight), int(picked.size()));
		for(j = 0; j < picked.size(); ++j)
			printf("%s\n", picked[j].c_str());
	}

	return 0;
}

