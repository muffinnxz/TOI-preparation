#include <bits/stdc++.h>
using namespace std;
void add_edge(vector<int> adj[],int v,int u)
{
	adj[v].push_back(u);
	adj[u].push_back(v);
}
void BFS(vector<int> adj[],int src,int V)
{
    bool visited[V];
	for(int i=0;i<V;i++)
	{
	 visited[i]=false;	
	}	
	list <int> q;
	visited[src] =true;
	q.push_back(src);
	while(!q.empty())
	{
		int s=q.front();
		cout <<s<<" ";
		q.pop_front();
		for(auto i =adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				q.push_back(*i);
			}
		}
	}
}
int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nv,ne;
	int v=7;
	vector <int> adj[v];
	add_edge(adj,1,2);
	add_edge(adj,1,3);
	add_edge(adj,1,4);
	add_edge(adj,2,5);
	add_edge(adj,3,6);
	add_edge(adj,3,7);
	add_edge(adj,4,8);
	add_edge(adj,5,9);
	add_edge(adj,6,10);
	BFS(adj,1,v);
	return 0;
}
