#include<bits/stdc++.h>
using namespace std;

void addedge(vector<int> graph[],int u,int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void BFS(vector<int> graph[],int source,int V)
{
	bool visited[V];
	for(int i=0;i<V;i++) visited[i] = false;
	
	queue<int> node;
	node.push(source);
	visited[source] = true;
	
	int u;
	while(!node.empty())
	{
		u = node.front();
		node.pop();
		cout<<u<<" ";
		for(auto x : graph[u])
			if(!visited[x])
			{
				visited[x] = true;
				node.push(x);
			}
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> graph[11];
	addedge(graph,1,2);
	addedge(graph,1,3);
	addedge(graph,1,4);
	addedge(graph,2,5);
	addedge(graph,3,6);
	addedge(graph,3,7);
	addedge(graph,4,8);
	addedge(graph,5,9);
	addedge(graph,6,10);
	
	BFS(graph,3,11);
}
