#include<bits/stdc++.h>
#define pii pair<int, pair<int,int> >
using namespace std;

int V, E, parent[100001];
priority_queue<pii, vector<pii>, greater<pii> > edge;

int findp(int u)
{
	if(parent[u] == 0) return u;
	return parent[u] = findp(parent[u]);
}

void kruskal()
{
	vector<pii> MST;
	while(!edge.empty() && MST.size() < V-1)
	{
		pii e = edge.top();
		edge.pop();
		
		int u = findp(e.second.first), v = findp(e.second.second);
		if(u != v)
		{
			MST.push_back(e);
			parent[u] = v;
		}
	}
	for(auto e:MST)
		cout << e.second.first << " " << e.second.second << "\n";
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> V >> E;
	
	for(int i=0;i<E;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge.push({w, {u, v}});
	}
	
	kruskal();
}
