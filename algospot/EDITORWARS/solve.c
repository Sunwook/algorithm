
#include <stdio.h>

//#define __D

#define		N_MAX	100

int PRE[N_MAX+5];
int IN[N_MAX+5]; 
int N;

int get_tree_left_count(int root, int start, int end)
{
	int count = end - start + 1;
	int i;
	for (i=0; i<count; ++i)
	{
		if (root == IN[start+i])
			break;
	}

	return i;
}

void print_post_order(int pre_start, int pre_end, int in_start, int in_end)
{
	int tree_num = pre_end - pre_start + 1;
	if (tree_num <= 0)
		return;

	int tree_root_val = PRE[pre_start];
	int tree_left_count = get_tree_left_count(tree_root_val, in_start, in_end);

	// LEFT
	print_post_order(pre_start+1, pre_start+tree_left_count, in_start, in_start+tree_left_count-1);

	// RIGHT
	print_post_order(pre_start+tree_left_count+1, pre_end, in_start+tree_left_count+1, in_end);

	// ROOT
	printf("%d ", tree_root_val);
}

int main(void)
{
	int tc, T;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &N);
#ifdef __D
		printf("#%d N(%d)\n", tc, N);
#endif
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &PRE[i]);
#ifdef __D
			printf("%d ",PRE[i]);
#endif
		}
#ifdef __D
		printf("\n");
#endif
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &IN[i]);
#ifdef __D
			printf("%d ",IN[i]);
#endif
		}
		
#ifdef __D
		printf("\n");
#endif

		print_post_order(1,N,1,N);
		printf("\n");
	}

	return 0;
}

