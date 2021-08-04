#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int> > graph[],int u,int v,int w)
{
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));
}

void BFS(vector<pair<int,int> > graph[],int V)
{
	vector<bool> visited(V+1,false);
	vector<int> dist(V+1,INT_MAX);
	
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	
	int u;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		
		visited[u] = true;
		
		for(auto v : graph[u])
		{
			if(!visited[v.first] && dist[u] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u] + v.second;
				q.push(v.first);
			}
		}
	}
	
	int ans = INT_MAX;
	for(int i=1;i<V+1;i++)
		ans = min(ans,dist[i]);
	cout<<ans * -1;
		
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int V;
	cin>>V;
	
	vector<pair<int,int> > graph[V+1];
	
	int u,v,w;
	for(int i=0;i<V-1;i++)
	{
		cin>>u>>v>>w;
		w *= -1;
		addEdge(graph,u,v,w);
	}
	
	BFS(graph,V);
}
