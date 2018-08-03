
#include <iostream>
using namespace std;
int dp[1001][4];
int home[1001][4];
int main()
{
	int N,r,g,b;
	cin>>N;
	for(int i=1; i<=N; i++)
	{
		cin>>r>>g>>b;
		home[i][1]=r;
		home[i][2]=g;
		home[i][3]=b;
	}
	dp[1][1]=home[1][1], dp[1][2]=home[1][2], dp[1][3]=home[1][3];
	for(int i=2; i<=N; i++)
	{
		dp[i][1]=home[i][1]+min(dp[i-1][2],dp[i-1][3]);
		dp[i][2]=home[i][2]+min(dp[i-1][1],dp[i-1][3]);
		dp[i][3]=home[i][3]+min(dp[i-1][1],dp[i-1][2]);
	}
	cout<<min(min(dp[N][1],dp[N][2]),dp[N][3])<<endl;
}
