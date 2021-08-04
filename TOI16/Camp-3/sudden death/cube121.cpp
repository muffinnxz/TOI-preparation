#include<bits/stdc++.h>
#define pii pair<int, pair<int,int> >
using namespace std;
int V, E, parent[100001], power[100001];
priority_queue<pii, vector<pii>, greater<pii> > edge;
int findp(int u)
{
	if(parent[u] == 0) return u;
	return parent[u] = findp(parent[u]);
}
void kruskal()
{
	int MST = 0, mstEdge = 0;
	while(!edge.empty() && mstEdge < V-1)
	{
		pii e = edge.top();
		edge.pop();
		
		int u = findp(e.second.first), v = findp(e.second.second);
		if(u != v)
		{
			MST += e.first;
			mstEdge++;
			parent[u] = v;
		}
	}
	cout << MST;
}
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> V;
	
	for(int i=1;i<=V;i++)
		cin >> power[i];
	
	cin >> E;
	for(int i=0;i<E;i++)
	{
		int u, v;
		cin >> u >> v;
		edge.push({power[u] + power[v], {u, v}});
	}
	
	kruskal();
}
