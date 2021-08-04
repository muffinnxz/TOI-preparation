#include<bits/stdc++.h>
#define pi pair<int,int>
#define pii pair<int, pi>
#define piii pair<int, pii>
using namespace std;

int N, p[101], S, D, F, M;
bool visited[101][101][2];
vector<pi> graph[101];

void solve()
{
	memset(visited, false, sizeof(visited));
	
	priority_queue<piii, vector<piii>, greater<piii> > q;
	q.push({0, {1, {S, 0}}}); // cost, free, node, fuel
	
	while(!q.empty())
	{
		int cost = q.top().first, free = q.top().second.first, u = q.top().second.second.first, f = q.top().second.second.second;
		q.pop();
		
		if(u == D && f == F)
		{
			cout << cost;
			break;
		}
		
		if(visited[u][f][free]) continue;
		visited[u][f][free] = true;
		
		if(free == 1) q.push({cost, {0, {u, F}}});
		if(f < F) q.push({cost + p[u], {free, {u, f+1}}});
		
		for(auto vw : graph[u])
		{
			int v = vw.first, w = vw.second;
			if(f >= w) q.push({cost, {free, {v, f-w}}});
		}
	}
}
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> p[i];
	
	cin >> S >> D >> F;
	
	cin >> M;
	for(int i=0;i<M;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	
	solve();
}
