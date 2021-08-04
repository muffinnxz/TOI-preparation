#include<bits/stdc++.h>
using namespace std;

int findset(vector<int> &subset,int u)
{
	if(subset[u] == -1) return u;
	subset[u] = findset(subset,subset[u]);
	return subset[u];
}

void kruskal(vector<pair<int,pair<int,int> > > edge,int V)
{
	vector<int> subset(V,-1);
	vector<pair<int,pair<int,int> > > MST;
	
	sort(edge.begin(),edge.end());
	
	for(auto E : edge)
	{
		int setu = findset(subset,E.second.first);
		int setv = findset(subset,E.second.second);
		if(setu != setv)
		{
			MST.push_back(E);
			subset[setu] = setv;
			if(MST.size() == V-1) break;		
		}
	}
	
	for(auto E : MST)
		cout<<E.second.first+1<<" "<<E.second.second+1<<'\n';
	
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int V,E;
	
	cin>>V>>E;
	
	vector<pair<int,pair<int,int> > > edge;
	
	int u,v,w;
	for(int i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		u-- , v--;
		edge.push_back(make_pair(w,make_pair(u,v)));
	}
	
	kruskal(edge,V);
}
