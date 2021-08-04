#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
#define pii pair<int,int>
#define piii pair<int,pii>
const int div_prime = 1000000007;

int V, E;

int find_set(vector<int> &parent_set,int u)
{
	if(parent_set[u] == -1) return u;
	parent_set[u] = find_set(parent_set,parent_set[u]);
	return parent_set[u];
}

int Kruskal(vector<piii> edge)
{
	vector<piii> MST;
	vector<int> parent_set(E,-1);
	sort(edge.begin(), edge.end());
	
	int dist = 0;
	for(int i=0;i<E && MST.size() < E-1;i++)
	{
		int set_u = find_set(parent_set,edge[i].second.first);
		int set_v = find_set(parent_set,edge[i].second.second);
		if(set_u != set_v)
		{
			MST.push_back(edge[i]);
			dist += edge[i].first;
			parent_set[set_u] = set_v;	
		}
	}
	return dist;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>V>>E;
	vector<piii> edge;
	
	int u,v,w,r;
	for(int i=0;i<E;i++)
	{
		cin>>u>>v>>w>>r;
		if(r == 0) edge.push_back(make_pair(w,make_pair(u,v)));
		else edge.push_back(make_pair(0,make_pair(u,v)));
	}
	
	int p;
	cin>>p;
	
	priority_queue<pii,vector<pii>,greater<pii> > price;
	int a,b;
	for(int i=0;i<p;i++)
	{
		cin>>a>>b;
		price.push(make_pair(b,a));	
	}
	
	sort(edge.begin(),edge.end());
	for(int i=0;i<E;i++)
		if(edge[i].first != 0)
		{
			while(price.top().second < edge[i].first) price.pop();
			edge[i].first = price.top().first;
		}
	
	cout<<Kruskal(edge);
}
