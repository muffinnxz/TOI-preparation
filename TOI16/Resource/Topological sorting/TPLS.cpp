#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[],int u,int v)
{
	graph[u].push_back(v);
}

void TPLSuntil(vector<int> graph[],int u,vector<bool> &visited,stack<int> &tpls)
{
	visited[u] = true;
	for(auto x : graph[u])
		if(!visited[x]) TPLSuntil(graph,x,visited,tpls);
	tpls.push(u);
}

void TPLS(vector<int> graph[],int V)
{
	vector<bool> visited(V,false);
	stack<int> tpls;
	
	for(int i=0;i<V;i++)
		if(!visited[i]) TPLSuntil(graph,i,visited,tpls);
		
	while(!tpls.empty())
	{
		cout<<tpls.top()<<" ";
		tpls.pop();
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int V = 6;
	vector<int> graph[V];
	addEdge(graph,5,0);
	addEdge(graph,5,2);
	addEdge(graph,2,3);
	addEdge(graph,3,1);
	addEdge(graph,4,0);
	addEdge(graph,4,1);
	
	TPLS(graph,V);
}
