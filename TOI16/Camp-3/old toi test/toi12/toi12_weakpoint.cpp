#include<bits/stdc++.h>
using namespace std;

int N, M, T = 1;
vector<int> graph[500001];
set<int> ap;
set<pair<int, int> > bdg;
int child[500001], low[500001], disc[500001];

int tarjan(int u, int p)
{	
	disc[u] = low[u] = T++;
	
	int cnt = 0;
	for(auto v : graph[u])
	{
		if(!disc[v]) // visited
		{
			cnt++;
			
			tarjan(v, u);
			
			child[u] += child[v];
			
			low[u] = min(low[u], low[v]);
			
			if((p != 0 && disc[u] <= low[v]) || (p == 0 && cnt > 1)) ap.insert(u); // find articulation point
			if(disc[u] < low[v])
			{
				// find bridge
				// cout << u << " " << v << "\n";
				bdg.insert({u, v});
			} 
		}
		else if(v != p) low[u] = min(low[u], disc[v]);
	}
	child[u] += 1;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	
	for(int i=0;i<N;i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	memset(child, 0, sizeof(child));
	
	tarjan(M, 0);
	
	int mx = 0, node;
	for(auto u : ap)
	{
		int sum = 0;
		for(auto v : graph[u])
			if((bdg.find({u,v}) != bdg.end() || bdg.find({v,u}) != bdg.end()) && disc[u] < disc[v]) 
				sum += child[v];
		if(u != M && mx < sum)
		{
			mx = sum;
			node = u;	
		}
	}
	cout << node << "\n" << mx;
}
