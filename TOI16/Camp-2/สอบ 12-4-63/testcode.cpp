#include<bits/stdc++.h>
using namespace std;

void DFSuntil(vector<int> graph[],bool visited[],int u,int d,int *t,bool *ANS)
{
	if(u == d || *ANS){
		*ANS = true;
		return;
	}
	visited[u] = true;
	*t = *t + 1;
	for(auto v : graph[u])
		if(!visited[v]) DFSuntil(graph,visited,v,d,t,ANS);
}

int DFS(vector<int> graph[],int V,int s,int d)
{
	bool visited[V];
	memset(visited,false,sizeof(visited));
	
	int t = 0;
	bool ANS = false;
	DFSuntil(graph,visited,s,d,&t,&ANS);
	
	return t;
}
