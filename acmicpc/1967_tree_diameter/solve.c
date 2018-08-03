
#include <stdio.h>

//#define __D
#define		MAX 	100000

int N;

typedef struct _node_s {
	struct _node_s* prev;
	int node;
	int distance;
} node_s;

node_s* TAIL[MAX+5];
int VISITED[MAX+5];
int CUR_DIST[MAX+5];

int front;
int rear;
int queue[MAX+5];

int max_distance, candidate_node;

void queueInit(void)
{
	front = 0;
	rear = 0;
}

int queueIsEmpty(void)
{
	return (front == rear);
}

int queueIsFull(void)
{
	if ((front + 1) % MAX == rear)
	{   
		return 1;
	}   
	else
	{   
		return 0;
	}   
}

int queueEnqueue(int value)
{
	if (queueIsFull())
	{
		printf("queue is full!");
		return 0;
	}
	queue[front] = value;
	front++;
	if (front == MAX)
	{
		front = 0;
	}

	return 1;
}

int queueDequeue(int *value)
{
	if (queueIsEmpty())
	{
		printf("queue is empty!");
		return 0;
	}
	*value = queue[rear];
	rear++;
	if (rear == MAX)
	{
		rear = 0;
	}
	return 1;
}



void init(void)
{
	for (int i=1; i<=N; i++)
	{
		TAIL[i] = NULL;
		VISITED[i] = 0;
		CUR_DIST[i] = 0;
	}
}

void deinit(void)
{
	node_s* node;
	node_s* tmp;
	for (int i=1; i<=N; i++)
	{
		node = TAIL[i];
		while(node != NULL)
		{
			tmp = node->prev;
			delete node;
			node = tmp;
		}
	}
}

void bfs(int start)
{
	max_distance = 0;
	candidate_node = 0;

	queueInit();
	queueEnqueue(start);
	VISITED[start] = 1;

	int parent, node;
	while (!queueIsEmpty())
	{
		if (queueDequeue(&parent) == 1)
		{
			//printf("%d ", parent);
			node_s* pNode = TAIL[parent];
#ifdef __D
			printf("dequeue: %d, total: %d\n", parent, CUR_DIST[parent]);
#endif
			while (pNode != NULL)
			{
				node = pNode->node;
				if (VISITED[node] == 0)
				{
#ifdef __D	
					printf("push: %d\n", node);
#endif
					VISITED[node] = 1;
					CUR_DIST[node] = CUR_DIST[parent] + pNode->distance;
					if (CUR_DIST[node] > max_distance)
					{
						max_distance = CUR_DIST[node];
						candidate_node = node;
					}

					queueEnqueue(node);
				}

				pNode = pNode->prev;
			}
		}
	}

}

int main(void)
{ 
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &N);
	init();
	int a,b,d;
	for (int i=1; i<=N; i++)
	{
		scanf("%d %d %d", &a, &b, &d);
#ifdef __D
		printf("%d %d %d\n", a, b, d);
#endif
		node_s* temp = new node_s;
		temp->prev = TAIL[a];
		temp->node = b;
		temp->distance = d;
		TAIL[a] = temp;

		temp = new node_s;
		temp->prev = TAIL[b];
		temp->node = a;
		temp->distance = d;
		TAIL[b] = temp;

#ifdef __D
		printf("\n");
#endif
	}


	bfs(1);

#ifdef __D
	printf("\nmax distance: %d, candidate_node: %d\n", max_distance, candidate_node);
#endif

	for (int i=1; i<=N; i++)
	{
		VISITED[i] = 0;
		CUR_DIST[i] = 0;
	}

	bfs(candidate_node);

#ifdef __D
	printf("\nmax distance: %d, candidate_node: %d\n", max_distance, candidate_node);
#endif

	deinit();

	printf("%d\n", max_distance);

	return 0;
}
