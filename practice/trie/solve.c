
#include <stdio.h>
#include <malloc.h>

#define __D

typedef struct _node {
	struct _node *child[26];
	char ch;
	int word;
} node_s;

node_s TRIE;

int get_len(char *str)
{
	int i=0;
	while(str[i] != '\n')
		++i;

	return i;
}

void init(void)
{
	for (int i=0; i<26; ++i)
	{
		TRIE.child[i] = NULL;
	}
}

void add_trie(node_s* node, char *str)
{
	if (*str == '\0')
	{
		printf("  null !!\n");
		node->word = 1;
		return;
	}

	int i = *str - 'A';
	if (node->child[i] == NULL)
	{
		node->child[i] = (node_s*)calloc(1, sizeof(node_s));
		node->child[i]->ch = *str;
	}
	printf("  added: %c\n", *str);
	add_trie(node->child[i], str+1);
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

int main(void)
{
	int tc, T;
	int N, M;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		init();
		char str[50];
		int ret;
		for (int i=0; i<2; ++i)
		{
			scanf("%s", str);
#ifdef __D
			printf("Add: %s\n", str);
#endif
			add_trie(&TRIE, str);

		}

		for (int i=0; i<4; ++i)
		{
			scanf("%s", str);
#ifdef __D
			printf("Find: %s\n", str);
#endif
			ret = find_trie(&TRIE, str);
#ifdef __D
			if (ret > 0)
				printf("  Found: %s\n", str);
			else
				printf("  fail to find: %s\n", str);
#endif
		}

	}

	return 0;
}


