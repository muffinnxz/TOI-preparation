/*
TASK: snack
LANG: C++
AUTHOR: Jeanipat Lapsuwannawong
CENTER: WU
*/

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[],int u,int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

int BFS(vector<int> graph[],int V,int s,int d)
{
	vector<bool> visited(V,false);
	queue<int> q;
	q.push(s);
	
	int u,t = 0;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		
		if(u == d) return t;
		
		visited[u] = true;
		t++;
		
		for(auto v : graph[u])
			if(!visited[v]) q.push(v);	
	} 
	return INT_MAX;
}

int DFS(vector<int> graph[],int V,int s,int d)
{
	vector<bool> visited(V,false);
	stack<int> stc;
	stc.push(s);
	
	int u,t = 0;
	while(!stc.empty())
	{
		u = stc.top();
		if(u == d) return t;
		
		if(!visited[u]) t++;
		visited[u] = true;
		
		for(auto v : graph[u])
			if(!visited[v]) { stc.push(v); break; }
		if(stc.top() == u) stc.pop();
	}
	return INT_MAX;
}

main()
{
	int V,E,S,D;
	cin>>V>>E>>S>>D;
	
	vector<int> graph[V];
	int u,v;
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		addEdge(graph,u,v);
	}
	
	int a = BFS(graph,V,S,D);
	int b = DFS(graph,V,S,D);
	
	if(a == b) cout<<"EQUAL";
	else if(a < b) cout<<"BREADTH";
	else cout<<"DEPTH";
}
