
#include <stdio.h>

int edge[20][20];
int reach[20];
int n, e;

void dfs(int vertex)
{
	int i;
	reach[vertex] = 1;
	for (i=1; i<=n; i++)
		if (edge[vertex][i] == 1 && !reach[i])
		{
			printf("%d -> %d, ",vertex,i);
			dfs(i);
		}
}

int main(void)
{
	int i,v1,v2,count=0;

	printf("Enter number of vertices, edges: ");
	scanf("%d%d",&n, &e);

	printf("Enter the edges: ");
	for (i=1; i<=e; i++)
	{
		scanf("%d%d",&v1,&v2);
		edge[v1][v2] = edge[v2][v1] = 1;
	}

	dfs(1);

	for (i=1; i<=n; i++)
		if(reach[i])
			count++;

	if (count == n)
		printf("\n Graph is connected");
	else
		printf("\n Graph is not connected");

	return 0;
}
