#include<bits/stdc++.h>
using namespace std;

#define endll '\n'
#define INF 999999

typedef struct{
	int u,v,w;
}EDGE;

void printpath(vector<int> parent,int u)
{
	if(u == -1) return;
	printpath(parent,parent[u]);
	cout<<u<<" ";
}

void addEdge(vector<pair<int,int> > graph[],int u,int v,int w)
{
	graph[u].push_back(make_pair(v,w));
	graph[v].push_back(make_pair(u,w));
}

void makeEdge(vector<EDGE> &edge,int u,int v,int w)
{
	EDGE tmp = {u,v,w};
	edge.push_back(tmp);
}

void BFS(vector<pair<int,int> > graph[],int V)
{
	bool visited[V];
	memset(visited,false,sizeof(visited));
	
	queue<int> q;
	q.push(0);
	
	cout<<"BFS : ";
	
	int u;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		
		visited[u] = true;
		cout<<u<<" ";
		for(auto v : graph[u])
			if(!visited[v.first])
			{
				visited[v.first] = true;
				q.push(v.first);
			}
	}
	cout<<endll;
}

void DFSuntil(vector<pair<int,int> > graph[],bool visited[],int u)
{
	visited[u] = true;
	cout<<u<<" ";
	for(auto v : graph[u])
		if(!visited[v.first]) DFSuntil(graph,visited,v.first);
}

void DFS(vector<pair<int,int> > graph[],int V)
{
	bool visited[V];
	memset(visited,false,sizeof(visited));
	cout<<"DFS : ";
	DFSuntil(graph,visited,0);
	cout<<endll;
}

void dijkstra(vector<pair<int,int> > graph[],int V)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0,0));
	vector<bool> visited(V,false);
	vector<int> dist(V,INF) , parent(V);
		
	dist[0] = 0;
	parent[0] = -1;
	
	pair<int,int> u;
	for(int i=0;i<V;i++)
	{
		u = q.top();
		q.pop();
		
		visited[u.second] = true;
		
		for(auto v : graph[u.second])
			if(!visited[v.first] && dist[u.second] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u.second] + v.second;
				parent[v.first] = u.second;
				q.push(make_pair(dist[v.first],v.first));
			}
	}
	
	cout<<"DIJLSTRA : ";
	for(int i=0;i<V;i++)
		cout<<dist[i]<<" ";
	cout<<endll; 
	cout<<"Parent : ";
		for(int i=0;i<V;i++)
			cout<<parent[i]<<" ";
	cout<<endll;
}

int findminkey(bool inSet[],int key[],int V)
{
	int minKey = INT_MAX , index = 0;
	for(int i=0;i<V;i++)
		if(key[i] < minKey && !inSet[i])
		{
			minKey = key[i];
			index = i;
		}
	return index;
}

void primMST(vector<pair<int,int> > graph[],int V)
{
	int key[V] , parent[V];
	bool inSet[V];
	memset(inSet,false,sizeof(inSet));
	for(int i=0;i<V;i++)
		key[i] = INT_MAX;
	
	key[0] = 0;
	parent[0] = -1;
	
	int u;
	for(int i=0;i<V-1;i++)
	{
		u = findminkey(inSet,key,V);
		inSet[u] = true;
		for(auto v : graph[u])
			if(!inSet[v.first] && v.second < key[v.first])
			{
				key[v.first] = v.second;
				parent[v.first] = u;
			}
	}
	
	cout<<"Prim MST : ";
	int sum = 0;
	for(int i=0;i<V;i++)
		sum += key[i];
	cout<<sum<<endll;
}

bool cmpEDGE(EDGE a ,EDGE b)
{
	return a.w < b.w;
}

void bellmanford(vector<EDGE> edge,int V)
{
	vector<int> dist(V,INF);
	vector<int> parent(V,-1);
	dist[0] = 0;
	
	for(int i=0;i<V-1;i++)
		for(auto e : edge)
			if(dist[e.u] + e.w < dist[e.v]) 
			{
				dist[e.v] = dist[e.u] + e.w;
				parent[e.v] = e.u;
			}
			
	bool isNegloop = false;
	for(auto e : edge)
		if(dist[e.u] + e.w < dist[e.v])
		{
			isNegloop = true;
			break;
		}
		
	cout<<"BELLMAN : ";
	if(isNegloop) cout<<"-1";
	else
	{
		for(int i=0;i<V;i++)
			cout<<dist[i]<<" ";
		cout<<endll;
		cout<<"Parent : ";
		for(int i=0;i<V;i++)
			cout<<parent[i]<<" ";
	}
	cout<<endll;
}

int findset(vector<int> parent,int u)
{
	if(parent[u] == -1) return u;
	return findset(parent,parent[u]);
}

void kruskalMST(vector<EDGE> edge,int V)
{
	vector<int> parent(V,-1);
	vector<EDGE> MST;
	
	sort(edge.begin(),edge.end(),cmpEDGE);
	
	for(auto e : edge)
	{
		int setu = findset(parent,e.u);
		int setv = findset(parent,e.v);
		if(setu != setv)
		{
			MST.push_back(e);
			parent[setu] = setv;
		}
	}
	
	int sum = 0;
	for(auto e : MST)
		sum += e.w;
	cout<<"Kruskal : "<<sum<<endll;
}

bool check_circle_undirected(vector<pair<int,int> > graph[],vector<bool> &visited,int u,int p)
{
	if(visited[u]) return true;
	visited[u] = true;
	for(auto v : graph[u])
		if(v.first != p) 
			if(check_circle_undirected(graph,visited,v.first,u)) return true;
	return false;
}

bool isCircleUndirected(vector<pair<int,int> > graph[],int V)
{
	vector<bool> visited(V,false);
	for(int i=0;i<V;i++)
		if(!visited[i] && check_circle_undirected(graph,visited,i,-1))
			return true;
	return false;
}

bool check_circle_directed(vector<pair<int,int> > graph[],vector<int> &color,int u)
{
	if(color[u] == 1) return false;
	if(color[u] == 2) return true;
	color[u] = 1;
	for(auto v : graph[u])
		if(check_circle_directed(graph,color,v.first)) return true;
	return false;
}

bool isCircleDirected(vector<pair<int,int> > graph[],int V)
{
	vector<int> color(V,0);
	for(int i=0;i<V;i++)
		if(color[i] == 0)
			if(check_circle_directed(graph,color,i)) return true;
	return false;
}



main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int V = 9 ,E = 14;
	
	vector<pair<int,int> >	graph[V];
	vector<EDGE> edge;
	
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
	
	makeEdge(edge,0,1,4);
	makeEdge(edge,0,7,8);
	makeEdge(edge,1,2,8);
	makeEdge(edge,1,7,11);
	makeEdge(edge,2,3,7);
	makeEdge(edge,2,5,4);
	makeEdge(edge,2,8,2);
	makeEdge(edge,3,4,9);
	makeEdge(edge,3,5,14);
	makeEdge(edge,4,5,10);
	makeEdge(edge,5,6,2);
	makeEdge(edge,6,7,1);
	makeEdge(edge,6,8,6);
	makeEdge(edge,7,8,7);
	
	BFS(graph,V);
	DFS(graph,V);
	dijkstra(graph,V);
	primMST(graph,V);
	bellmanford(edge,V);
	kruskalMST(edge,V);
}
