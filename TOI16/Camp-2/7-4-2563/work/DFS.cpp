#include<bits/stdc++.h>
using namespace std;

int V,E;

vector<vector<int> > visited;

void addedge(vector<int> graph[],int u,int v)
{
	graph[u].push_back(v);
}

void init()
{
	for(int i=0;i<V;i++)
		visited.push_back(vector<int> (V,0));
}

void DFS(vector<int> graph[],int source,int u)
{
	visited[source][u] = 1;
	for(auto x : graph[u])
		if(!visited[source][x]) DFS(graph,source,x);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>V>>E;
	
	vector<int> graph[V];
	
	int u,v;
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		addedge(graph,u,v);
	}
	
	init();
	for(int i=0;i<V;i++)
		DFS(graph,i,i);
		
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			cout<<visited[i][j]<<" ";
		cout<<endl;
	}
}
