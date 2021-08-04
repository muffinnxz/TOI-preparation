#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

int V,E;
set<pair<int,pair<int,int> > > G;

int findset(vector<int> &parent,int u)
{
	if(parent[u] == -1) return u;
	parent[u] = findset(parent,parent[u]);
	return parent[u];
}

void kruskal()
{
	vector<int> subset(V,-1);
	set<pair<int,pair<int,int> > > T;
	
	for(auto e : G)
	{
		int setu = findset(subset,e.second.first);
		int setv = findset(subset,e.second.second);
		
		if(setu != setv)
		{
			T.insert(e);
			subset[setu] = setv;
			if(T.size() == V-1) break;
		}
	}
	
	if(T.size() < V-1) cout<<"-1"<<endll;
	else
	{
		int sum = 0;
		for(auto e : T)
			sum += e.first;
		G = T;
		cout<<sum<<endll;
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>V>>E;
	
	int u,v,w;
	for(int i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		u-- , v--;
		
		G.insert(make_pair(w,make_pair(u,v)));
		
		kruskal();
	}
}
