#include<bits/stdc++.h>
using namespace std;

#define INF 999999

typedef struct{
	int u,v,w;
}EDGE;

void addEdge(vector<EDGE> &edge,int u,int v,int w)
{
	EDGE tmp; tmp.u = u; tmp.v = v; tmp.w = w;
	edge.push_back(tmp);
}

void bellman_ford(vector<EDGE> edge,int src,int V)
{
	vector<int> dist(V,INF);
	dist[src] = 0;
	
	for(int i=0;i<V-1;i++)
		for(auto x : edge)
		{
			if(dist[x.u] + x.w < dist[x.v]) dist[x.v] = dist[x.u] + x.w;
			for(auto x : dist)
				cout<<x<<" ";
			cout<<"\n";
		}
			
	
	bool Negativeloop = false;
	for(auto x : edge)
		if(dist[x.u] + x.w < dist[x.v]) { Negativeloop = true; break; } 
		
	if(Negativeloop)
		cout<<"Negative loop";
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<EDGE> edge;
	
	addEdge(edge,0,1,4);
	addEdge(edge,0,7,8);
	addEdge(edge,1,2,8);
	addEdge(edge,1,7,11);
	addEdge(edge,2,3,7);
	addEdge(edge,2,5,4);
	addEdge(edge,2,8,2);
	addEdge(edge,3,4,9);
	addEdge(edge,3,5,14);
	addEdge(edge,4,5,10);
	addEdge(edge,5,6,2);
	addEdge(edge,6,7,1);
	addEdge(edge,6,8,6);
	addEdge(edge,7,8,7);
	
	bellman_ford(edge,0,9);
}
