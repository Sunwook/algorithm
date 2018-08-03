
// TSP: Traveling Salesman Problem
// Ch 6 Exhaustive Search
// Ch 9 DP
// Ch 11 Search / Heuristic / MST / IP

#include <stdio.h>

#include <string>
#include <vector>
#include<cmath>


#define MAX		10

#define log		printf

using namespace std;


const double INF = 1e200;

// 도시의 수
int n;

// 두 도시간의 거리를 저장하는 배열
double dist[MAX][MAX];

// path: 지금까지 만든 경로
// visited: 각 도시의 방문 여부
// currentLength: 지금까지 만든 경로의 길이
// 나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다
double spath(vector<int>& path, vector<bool>& visited, double curLen)
{
	double ret = INF;

	if (path.size() == n)
		return curLen + dist[path[0]][path.back()];

	for (int next = 0; next < n; ++next)
	{
		if (visited[next]) 
			continue;

		int here = path.back();
		path.push_back(next);
		visited[next] = true;

		double cand = spath(path, visited, curLen + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}

	return ret;
}

double cache[MAX][1<<MAX]; // -1로 초기화해 둔다.

// here: 현재 위치
// visited: 각 도시의 방문 여부
// here 에서 시작해 남은 도시들을 방문할 수 있는 최단 경로의 길이를      반환한다.
// 나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다
double sPath2(int here, int visited) 
{
	// 기저 사례: 모든 도시를 다 방문했을 때는 0번 도시로 돌아가고 종료한다
	if (visited == (1<<n) - 1)
		return dist[here][0];

	double& ret = cache[here][visited];
	if (ret > 0)
		return ret;

	ret = INF;

	for (int next = 0; next < n; ++next)
	{
		if (visited & (1<<next))
			continue;

		double cand = dist[here][next] + sPath2(next, visited + (1<<next));
		ret = min(ret, cand);
	}

	return ret;

}

int main()
{
	int i, j;

	// Read from file
	//freopen("packing_sample.txt", "r", stdin);

	scanf("%d", &input_count);
	log("%d\n", input_count);

	for (i=0; i<input_count; i++)
	{   

	}   

	return 0;
}

