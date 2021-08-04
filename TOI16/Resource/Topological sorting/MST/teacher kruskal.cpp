#include<bits/stdc++.h>
using namespace std;

class EDGE{
	public : 
	int u;
	int v;
	int w;
};

class Graph{
	public :
	int V;
	int E;
	EDGE *edge;
};

Graph* create_graph(int V,int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new EDGE[graph->E * sizeof(EDGE)];	
}

void addEdge(Graph *graph,int i,int u,int v,int w)
{
	graph->edge[i].u = u;
	graph->edge[i].v = v;
	graph->edge[i].w = w;
}

bool edgeCMP(EDGE a,EDGE b)
{
	return a.w < b.w;
}

int findset(int parent[],int node)
{
	if(parent[node] == -1) return node;
	return findset(parent,parent[node]);
}

void kruskal(Graph *graph)
{
	int V = graph->V;
	int E = graph->E;
	EDGE MST[V];
	int e = 0;
	int i = 0;
	
	sort(graph->edge,graph->edge + graph->E,edgeCMP);
	
	int parent[V];
	for(int x=0;x<V;x++) parent[x] = -1;
	
	while(e < V-1 && i < graph->E)
	{
		EDGE now = graph->edge[i++];
		
		int set_u = findset(parent,now.u);
		int set_v = findset(parent,now.v);
		
		if(set_u != set_v)
		{
			MST[e++] = now;
			parent[set_u] = set_v;
		}
	}
	
	int sum = 0;
	for(i=0;i<e;i++)
	{
		cout<<MST[i].u<<" - "<<MST[i].v<<" = "<<MST[i].w<<"\n";
		sum += MST[i].w;
	}
	cout<<"MST : "<<sum;
}

main()
{
	int V = 9,E = 14;
	
	Graph *graph = create_graph(V,E);
	
	/*addedge(graph,0,0,1,28);
	addedge(graph,1,0,5,10);
	addedge(graph,2,1,6,14);
	addedge(graph,3,1,2,16);
	addedge(graph,4,2,3,12);
	addedge(graph,5,3,4,22);
	addedge(graph,6,3,6,18);
	addedge(graph,7,4,6,24);
	addedge(graph,8,4,5,25);*/
	
	addEdge(graph,0,0,1,4);
	addEdge(graph,1,0,7,8);
	addEdge(graph,2,1,2,8);
	addEdge(graph,3,1,7,11);
	addEdge(graph,4,2,3,7);
	addEdge(graph,5,2,5,4);
	addEdge(graph,6,2,8,2);
	addEdge(graph,7,3,4,9);
	addEdge(graph,8,3,5,14);
	addEdge(graph,9,4,5,10);
	addEdge(graph,10,5,6,2);
	addEdge(graph,11,6,7,1);
	addEdge(graph,12,6,8,6);
	addEdge(graph,13,7,8,7);
	
	kruskal(graph);
}
