
#include <stdio.h>

#define		MAX 	26	
int N;

typedef struct _node {
	int left;
	int right;
	int value;
} node_s;

node_s TREE[30];

inline char getNodeValue(int node)
{
	return 'A' + TREE[node].value - 1;
}

void pre_order(int node)
{
	// root
	printf("%c", getNodeValue(node));

	// left
	if (TREE[node].left != 0)
		pre_order(TREE[node].left);

	// right
	if (TREE[node].right != 0)
		pre_order(TREE[node].right);
}

void in_order(int node)
{
	// left
	if (TREE[node].left != 0)
		in_order(TREE[node].left);

	// root
	printf("%c", getNodeValue(node));

	// right
	if (TREE[node].right != 0)
		in_order(TREE[node].right);
}

void post_order(int node)
{
	// left
	if (TREE[node].left != 0)
		post_order(TREE[node].left);

	// right
	if (TREE[node].right != 0)
		post_order(TREE[node].right);

	// root
	printf("%c", getNodeValue(node));
}

int main(void)
{ 
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &N);
	char str[5];
	int index;
	for (int i=1; i<=N; i++)
	{
		scanf("%s", &str[0]);
		index = str[0] - 'A' + 1;

		TREE[index].value = index;
		scanf("%s", &str[0]);
		if (str[0] != '.')
			TREE[index].left = str[0] - 'A' + 1;
		else
			TREE[index].left = 0;

		scanf("%s", &str[0]);
		if (str[0] != '.')
			TREE[index].right = str[0] - 'A' + 1;
		else
			TREE[index].right = 0;
	}

	/*
	for (int i=1; i<=N; i++)
		printf("TREE[%d], left(%d), right(%d)\n", i, TREE[i].left, TREE[i].right);
	*/

	pre_order(1);
	printf("\n");
	in_order(1);
	printf("\n");
	post_order(1);

	return 0;
}
