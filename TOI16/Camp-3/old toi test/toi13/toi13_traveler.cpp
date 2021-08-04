#include<bits/stdc++.h>
#define pi pair<int,int>
#define pii pair<int, pi>
using namespace std;
int V, E, s, t, budget, dist[2][10001];
bool visited[10001];
vector<pair<int,int > > graph[10001];
void solve(int start, int d)
{
	memset(visited,false,sizeof(visited));
	for(int i=0;i<V;i++)
		dist[d][i] = INT_MAX;
	
	priority_queue<pi, vector<pi>, greater<pi> > q;
	q.push({0, start});
	visited[start] = true;
	dist[d][start] = 0;
	
	for(int i=0;i<V;i++)
	{
		int u = q.top().second;
		q.pop();
		
		visited[u] = true;
		
		for(auto v : graph[u])
		{
			if(!visited[v.first] && dist[d][u] + v.second < dist[d][v.first])
			{
				dist[d][v.first] = dist[d][u] + v.second;
				q.push({dist[d][v.first], v.first});
			}
		}
	}
}
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> V >> E;
	cin >> s >> t >> budget;
	
	for(int i=0;i<E;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	
	solve(s, 0);
	if(dist[0][t] <= budget)
	{
		cout << t << " " << dist[0][t] << " " << 0;
		exit(0);
	}
	
	solve(t, 1);
	
	int dest, budg, nearest_dist = INT_MAX;
	for(int i=0;i<V;i++)
		if(dist[1][i] < nearest_dist && dist[0][i] <= budget)
		{
			dest = i;
			budg = dist[0][i];
			nearest_dist = dist[1][i];
		}
	
	cout << dest << " " << budg << " " << nearest_dist;
}

