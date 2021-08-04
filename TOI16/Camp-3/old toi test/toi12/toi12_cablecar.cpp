#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

int V, E, S, D, P;
vector<pi> graph[2501];

void solve()
{
	vector<bool> visited(V, false);
	
	priority_queue<pi> q;
	q.push({INT_MAX, S});
	
	while(!q.empty())
	{
		int u = q.top().second, w = q.top().first;
		q.pop();
		
		//cout << u << "\n";
		
		if(u == D)
		{
			cout << ceil(P/double(w-1));
			//cout << "ANS : " << P <<" " << w;
			break;
		}
		
		visited[u] = true;
		
		for(auto vw : graph[u])
			if(!visited[vw.first]) q.push({min(w, vw.second), vw.first});
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> V >> E;
	for(int i=0;i<E;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	
	cin >> S >> D >> P;
	
	solve();
}
