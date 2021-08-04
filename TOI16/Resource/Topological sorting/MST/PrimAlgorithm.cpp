#include<bits/stdc++.h>
using namespace std;

#define INF 999999

void addEdge(vector<pair<int,int> > graph[],int u,int v,int w)
{
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));
}

int minWeight(int weight[],bool inSet[],int V)
{
	int minW = INT_MAX, node = 0;
	for(int i=0;i<V;i++)
		if(!inSet[i] && weight[i] < minW)
		{
			minW = weight[i];
			node = i;
		}
	return node;
}

void primAlgorithm(vector<pair<int,int> > graph[],int V)
{
	int weight[V];
	int parent[V];
	bool inSet[V];
	for(int i=0;i<V;i++) weight[i] = INF,inSet[i] = false;
	
	weight[0] = 0;
	parent[0] = -1;
	
	for(int i=0;i<V-1;i++)
	{
		int u = minWeight(weight,inSet,V);
		inSet[u] = true;
		for(auto x : graph[u])
			if(!inSet[x.first] && x.second < weight[x.first]) parent[x.first] = u,weight[x.first] = x.second;
	}
	
	int mst = 0;
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<" - "<<i<<" = "<<weight[i]<<"\n";	
		mst += weight[i];
	}
	cout<<"MST : "<<mst;
}

main()
{
	int V = 9;
	vector<pair<int,int> > graph[V];
	
	addEdge(graph,0,1,4);
	addEdge(graph,0,7,8);
	addEdge(graph,1,2,8);
	addEdge(graph,1,7,11);
	addEdge(graph,2,3,7);
	addEdge(graph,2,5,4);
	addEdge(graph,2,8,2);
	addEdge(graph,3,4,9);
	addEdge(graph,3,5,14);
	addEdge(graph,4,5,10);
	addEdge(graph,5,6,2);
	addEdge(graph,6,7,1);
	addEdge(graph,6,8,6);
	addEdge(graph,7,8,7);
	
	primAlgorithm(graph,V);
}
