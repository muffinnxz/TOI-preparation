#include<bits/stdc++.h>
#define pi pair<int,int>
#define pii pair<int, pi>
#define INF 1e9
using namespace std;

int N, P, U, E, T;
vector<pi> graph[2001];

int dp[2001][2001];

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> P >> U >> E;
	
	vector<pi> P_edge;
	for(int i=0;i<E;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}
	
	for(int i=0;i<N;i++)
		for(int j=0;j<E;j++)
			dp[i][j] = INF;
	
	dp[P][0] = 0;
	
	for(int e=0;e<N;e++)
		for(int u=0;u<N;u++)
			for(auto v:graph[u])
				dp[v.first][e+1] = min(dp[v.first][e+1], dp[u][e] + v.second);
	
	cin >> T;
	
	while(T--)
	{
		int h;
		cin >> h;
		
		int mn = INF;
		for(int i=0;i<N-1;i++)
			mn = min(mn, dp[U][i] + (i-1)*h);
		cout << mn << " ";
	}
}
