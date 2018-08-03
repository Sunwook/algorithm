
#include <stdio.h>
#include <time.h>

#define 	__D

//#define __DFS
#define __BFS

#define 	MAX		100

char D[MAX + 1][MAX + 1];
int VISIT[MAX+1][MAX+1];

int H,W;
int ans;

int dh[4] = {1, -1, 0, 0};
int dw[4] = {0, 0, 1, -1};

#ifdef __BFS
int Q[20001];
int Q_SIZE = 20000;

int head;
int tail;

void enqueue(int h, int w, int dist)
{
	Q[tail] = h;
	if (tail - 1 < 0)
		tail = Q_SIZE;
	else
		--tail;

	Q[tail--] = w;
	Q[tail--] = dist;
}

int dequeue(int *h, int *w, int *dist)
{
	if (head == tail)
		return 0;

	*h = Q[head];
	if (head - 1 < 0)
		head = Q_SIZE;
	else
		--head;

	*w = Q[head--];
	*dist = Q[head--];

	return 1;
}


void bfs(int start_h, int start_w)
{

	enqueue(start_h, start_w, 0);
	VISIT[start_h][start_w] = 1;

	int h,w;
	int i, next_h, next_w, dist = 0;;
	while (dequeue(&h,&w, &dist))
	{
#ifdef __D
		printf("\nCurrent (%d,%d) dist(%d)", h, w, dist);
#endif
		if (D[h][w] == 'G')
		{
			if (dist < ans)
				ans = dist;

			return;
		}

		for (i=0; i<4; i++)
		{
			next_h = h + dh[i];
			next_w = w + dw[i];

			if ((D[next_h][next_w] == '.' || D[next_h][next_w] == 'G') && !VISIT[next_h][next_w])
			{
				//dfs(next_h, next_w, dist + 1);
#ifdef __D
				printf("\nQueueing (%d,%d) dist(%d)", next_h, next_w, dist+1);
#endif
				VISIT[next_h][next_w] = 1;
				enqueue(next_h,next_w, dist + 1);
			}
		}
	}

}

#endif

#ifdef __DFS
void dfs(int h, int w, int dist)
{
#ifdef __D
	printf("\nCurrent (%d,%d)", h, w);
#endif
	if (D[h][w] == 'G')
	{
		if (dist < ans)
			ans = dist;

		return;
	}

	VISIT[h][w] = 1;

	int i, next_h, next_w;
	for (i=0; i<4; i++)
	{
		next_h = h + dh[i];
		next_w = w + dw[i];

		if ((D[next_h][next_w] == '.' || D[next_h][next_w] == 'G') && !VISIT[next_h][next_w])
		{
			dfs(next_h, next_w, dist + 1);
		}
	}
}
#endif

int main(void)
{ 
	int tc, T;
	int i,j;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (tc = 1; tc <= T; ++tc)
	{
		scanf("%d %d", &H, &W);
#ifdef __D
		printf("#%d: %d x %d\n", tc, H, W);
#endif
		for (i=0; i<H; i++)
		{
			scanf("%s", &D[i]);
#ifdef __D
			printf("%s\n", D[i]);
#endif
		}

	/*
		// Set boundary
		for (i=0; i<=H+1; i++)
		{
			D[i][0] = 2;
			D[i][W+1] = 2;
		}
		for (i=0; i<=W+1; i++)
		{
			D[0][i] = 2;
			D[H+1][i] = 2;
		}
	*/


		// ALGO
		int found = 0;
		for (i=0; i<H; i++)
		{
			for (j=0; j<W; j++)
				if (D[i][j] == 'S')
				{
#ifdef __D
					printf("  Start from (%d,%d)\n", i, j);
#endif
					found = 1;
					break;
				}
			if (found)
				break;
		}

		ans = H * W;


		head = 0;
		tail = 0;

		/*
		int a,b,c;
		enqueue(1,1,0);
		enqueue(2,1,1);
		enqueue(3,4,2);
		dequeue(&a,&b,&c);
		printf("\n(%d,%d,%d)",a,b,c);
		dequeue(&a,&b,&c);
		printf("\n(%d,%d,%d)",a,b,c);
		dequeue(&a,&b,&c);
		printf("\n(%d,%d,%d)",a,b,c);
		*/

#ifdef __BFS
		bfs(i,j);
#endif

#ifdef __DFS
		dfs(i,j, 0);
#endif
		
		// OUTPUT

#ifdef __D
		printf("\nanswer: ");
#endif
		printf("%d\n", ans);

#ifdef __D
		printf("------------------\n\n");
#endif

		// Clear
		for (i=0; i<H; i++)
			for (j=0; j<W; j++)
			{
				D[i][j] = 0;
				VISIT[i][j] = 0;
			}

#ifdef __BFS
		for (i=0; i< 20000; i++)
			Q[i] = 0;
#endif

	}


	return 0;
}

