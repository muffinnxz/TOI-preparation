#include<bits/stdc++.h>
using namespace std;

#define INF 999999

void addEdge(vector<pair<int,int> > graph[],int u,int v,int w)
{
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));
}

void printpath(vector<int> parent,int u)
{
	if(u == -1)	return;
	printpath(parent,parent[u]);
	cout<<u<<" ";
}

void dijkstraAlgorithm(vector<pair<int,int> > graph[],int src,int end,int V)
{
	vector<int> dist(V,INF),parent(V);
	vector<bool> visited(V,false);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	
	q.push(make_pair(0,src));
	dist[src] = 0;
	parent[src] = -1;
	
	int u;
	for(int i=0;i<V;i++)
	{
		u = q.top().second;
		q.pop();
		
		visited[u] = true;
		
		for(auto v : graph[u])
		{
			if(!visited[v.first] && dist[u] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u] + v.second;
				parent[v.first] = u;
				q.push(make_pair(dist[v.first],v.first));
			}
		}
	}
	
	printpath(parent,end);
	
	cout<<endl<<dist[end];
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int V = 9, E = 14;
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
	
	dijkstraAlgorithm(graph,0,4,V);
}
