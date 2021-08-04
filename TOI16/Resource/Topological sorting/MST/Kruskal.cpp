#include<bits/stdc++.h>
using namespace std;

typedef struct Edge{
	int u,v,w;
}EDGE;

void addEdge(vector<EDGE> &edge,int u,int v,int w)
{
	EDGE tmp = {u,v,w};
	edge.push_back(tmp);
}

bool cmpEDGE(EDGE a,EDGE b)
{
	return a.w < b.w;
}

int findset(int parent[],int node)
{
	if(parent[node] == -1) return node;
	parent[node] = findset(parent,parent[node])
	return parent[node];
}

void kruskal(vector<EDGE> edge,int V,int E)
{	
	int parent[V];
	memset(parent,-1,sizeof(parent[0]) * V);
	vector<EDGE> mst;
	
	sort(edge.begin(),edge.end(),cmpEDGE);
		
	for(int i=0;i<E && mst.size() < V-1;i++)
	{
		int set_u = findset(parent,edge[i].u);
		int set_v = findset(parent,edge[i].v);
		if(set_u != set_v)
		{
			mst.push_back(edge[i]);
			parent[set_u] = set_v;	
		}
	}
	
	int sum = 0;
	for(auto x : mst)
	{
		cout<<x.u<<" - "<<x.v<<" = "<<x.w<<"\n";
		sum += x.w;
	}
	cout<<"MST : "<<sum<<"\n";
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int V = 9, E = 14;
	
	vector<EDGE> edge;
	
	/*addEdge(edge,0,1,28);
	addEdge(edge,0,5,10);
	addEdge(edge,1,6,14);
	addEdge(edge,1,2,16);
	addEdge(edge,2,3,12);
	addEdge(edge,3,4,22);
	addEdge(edge,3,6,18);
	addEdge(edge,4,6,24);
	addEdge(edge,4,5,25);*/
	
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
	
	kruskal(edge,V,E);
}
