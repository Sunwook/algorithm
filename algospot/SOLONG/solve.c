
#include <stdio.h>
#include <malloc.h>

#define __D

#define		N_MAX	10000
#define		M_MAX	20000



typedef struct _node {
	struct _node *child[26];
	char ch;
	int word;
	int prio;
	int auto_fill;
} node_s;

node_s TRIE;


typedef struct _string {
	int prio;
	char dic[11];
} string_s;

string_s DIC[N_MAX+5];
string_s* SDIC[N_MAX+5];

int N, M;

int get_len(char *str)
{
	int i=0;
	while(str[i] != '\n')
		++i;

	return i;
}

void str_copy(char* src, char* dst)
{
	while (*dst != '\0')
	{
		*src = *dst;
		++src, ++dst;
	}

	*src = '\0';
}
int check_letter(char* s1, char* s2)
{
	while(*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			if (*s1 > *s2)
				return 1;
			else
				return 0;
		}

		++s1, ++s2;
	}

	return 0;

}
void quick_sort(int first, int last)
{
	int pivot, i, j;
	string_s* temp;
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (SDIC[i]->prio >= SDIC[pivot]->prio && i < last)
			{
				/*
				if (SDIC[i]->prio == SDIC[pivot]->prio && i != pivot)
				{
					printf("same prio %d: %s  %d:%s\n", i, SDIC[i]->dic,  pivot, SDIC[pivot]->dic);
					if (check_letter(SDIC[i]->dic, SDIC[pivot]->dic) == 0)
					{
						printf("stop!!\n");
						break;
					}
				}
				*/

				i++;
			}
			while (SDIC[j]->prio < SDIC[pivot]->prio)
			{
				j--;
			}

			if (i < j)
			{
				/*
				if(SDIC[i]->prio == SDIC[j]->prio)
				{
					printf("same prio, (%d) prio %d (%d) prio %d!!!!!!!!!!!!!!!!\n",i, SDIC[i]->prio, j, SDIC[j]->prio);
					if (check_letter(SDIC[i]->dic, SDIC[j]->dic) > 0)
					{
						temp = SDIC[i];
						SDIC[i] = SDIC[j];
						SDIC[j] = temp;
					}
				}
				else
				 */
				{
					temp = SDIC[i];
					SDIC[i] = SDIC[j];
					SDIC[j] = temp;
				}
			}
		}

		temp = SDIC[pivot];
		SDIC[pivot] = SDIC[j];
		SDIC[j] = temp;

		quick_sort(first, j - 1);
		quick_sort(j + 1, last);
	}
}

void init(void)
{
	for (int i=0; i<26; ++i)
	{
		TRIE.child[i] = NULL;
		TRIE.word = 0;
		TRIE.prio = 0;
	}
}

void add_trie(node_s* node, char *str, int prio)
{
	if (*str == '\0')
	{
#ifdef __D
		//printf("  null !!\n");

		printf("  prio: %d\n", prio);
#endif
		node->word = 1;
		node->prio = prio;
		return;
	}

	int i = *str - 'A';
	if (node->child[i] == NULL)
	{
		node->child[i] = (node_s*)calloc(1, sizeof(node_s));
		node->child[i]->ch = *str;
	}
#ifdef __D
	printf("  added: %c\n", *str);
#endif
	add_trie(node->child[i], str+1, prio);
}

int find_trie(node_s* node, char *str)
{
	if (*str == '\0')
	{
		if (node->word == 1)
		{
			printf("  found !!\n");
			return 1;
		}
		else
		{
			printf("  not found !!\n");
			return -1;
		}
	}

	int i = *str - 'A';
	if (node->child[i] == NULL)
	{
		printf("  not found !!\n");
		return -1;
	}

	return find_trie(node->child[i], str+1);
}


void print_data(void)
{
	for (int i=1; i<=N; ++i)
	{
		printf("#%d %s (prio: %d)\n", i, SDIC[i]->dic, SDIC[i]->prio);
	}
}

int get_count(char* str)
{

	return 1;
}


int main(void)
{
	int tc, T;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &N, &M);
#ifdef __D
		printf("#%d N(%d) M(%d)\n", tc, N, M);
#endif
		char str[11];
		int prio;
		for (int i = 1; i <= N; i++)
		{
			scanf("%s %d", str, &prio);
#ifdef __D
			printf("%s %d\n",str, prio);
#endif
			//add_trie(&TRIE, str, prio);
			DIC[i].prio = prio;
			str_copy(DIC[i].dic, str);

			SDIC[i] = &DIC[i];
		}

		
#ifdef __D
		printf("before data\n");
		print_data();
#endif

		// sort
		quick_sort(1, N);


#ifdef __D
		printf("\nafter sorting\n");
		print_data();
#endif

		int ans = 0;
		for (int i = 1; i <= M; i++)
		{
			scanf("%s", str);
#ifdef __D
			printf("%s ", str);
#endif
			ans += get_count(str);
		}
#ifdef __D
		printf("\n");
#endif

		printf("%d\n", ans);
	}

	return 0;
}

