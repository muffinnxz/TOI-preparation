#include<bits/stdc++.h>
using namespace std;

int n, m, location[11][3], item[11][3], graph[11][11], mn = INT_MAX;
bool visited[11];

int find_graph(int u, int v)
{
	int dist = 0;
	for(int i=0;i<3;i++)
		dist += (location[v][i] - location[u][i]) * (location[v][i] - location[u][i]);
	return dist;
}

void dfs(int u, int A, int B, int C, int dist)
{
	if (A >= n && B >= n && C >= n)
	{
		mn = min(mn, dist);
		return;
	}
	
	for(int i=1;i<=m;i++)
		if(!visited[i]) 
		{
			visited[i] = true;
			dfs(i, A+item[i][0], B+item[i][1], C+item[i][2], dist + graph[u][i]);
			visited[i] = false;
		}
		
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> location[0][0] >> location[0][1] >> location[0][2];
	
	cin >> m;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<3;j++)
			cin >> location[i][j];
		for(int j=0;j<3;j++)
			cin >> item[i][j];
	}
		
	for(int i=0;i<=m;i++)
		for(int j=i+1;j<=m;j++)
		{
			int dist = find_graph(i, j);
			graph[i][j] = dist;
			graph[j][i] = dist;
		}
	
	memset(visited, false ,sizeof(visited));
	
	visited[0] = true;
	dfs(0, 0, 0, 0, 0);
	
	cout << mn;		
}
