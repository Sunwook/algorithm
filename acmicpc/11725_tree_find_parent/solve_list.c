
#include <stdio.h>

//#define __D
#define		MAX 	100000

int N;

typedef struct _node_s {
	struct _node_s* prev;
	int data;
} node_s;

node_s* TAIL[MAX+5];
int PARENT[MAX+5];
int VISITED[MAX+5];

int front;
int rear;
int queue[MAX+5];

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
	//for (int i=1; i<=MAX; i++)
	for (int i=1; i<=N; i++)
	{
		TAIL[i] = NULL;
		PARENT[i] = 0;
		VISITED[i] = 0;
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

int main(void)
{ 
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &N);
	init();
	int a,b;
	for (int i=1; i<N; i++)
	{

		scanf("%d %d", &a, &b);
#ifdef __D
		printf("%d %d\n", a, b);
#endif
		if (TAIL[a] == NULL)
		{
			TAIL[a] = new node_s;
			TAIL[a]->prev = NULL;
			TAIL[a]->data = b;
		}
		else
		{
			node_s* temp = new node_s;
			temp->prev = TAIL[a];
			temp->data = b;
			TAIL[a] = temp;
		}

		if (TAIL[b] == NULL)
		{
			TAIL[b] = new node_s;
			TAIL[b]->prev = NULL;
			TAIL[b]->data = a;
		}
		else
		{
			node_s* temp = new node_s;
			temp->prev = TAIL[b];
			temp->data = a;
			TAIL[b] = temp;
		}
	}

	queueInit();
	queueEnqueue(1);
	VISITED[1] = 1;

	while (!queueIsEmpty())
	{
		int parent;
		if (queueDequeue(&parent) == 1)
		{
			//printf("%d ", parent);
			node_s* node = TAIL[parent];
			int data;
			while (node != NULL)
			{
				data = node->data;
				//if (PARENT[data] == 0)
					//PARENT[data] = parent;

				if (VISITED[data] == 0)
				{
					//if (PARENT[data] == 0)
					PARENT[data] = parent;
					queueEnqueue(data);
					VISITED[parent] = 1;
				}

				node = node->prev;
			}
		}
	}

	for (int i=2; i<=N; i++)
	{
		printf("%d\n",PARENT[i]);
	}

	deinit();

	return 0;
}
