/*
TASK: supervalentine
LANG: C++
AUTHOR: Jeanipat Lapsuwannawong
CENTER: WU
*/
#include<bits/stdc++.h>
using namespace std;

typedef struct{
	int u,v,w;
}EDGE;

int V,E;
vector<EDGE> edge;

bool cmpEDGE(EDGE a , EDGE b)
{
	return a.w > b.w;
}

int findset(vector<int> &subset,int u)
{
	if(subset[u] == -1) return u;
	subset[u] = findset(subset,subset[u]);
	return subset[u];
}

void kruskal()
{
	vector<int> subset(V,-1);
	vector<EDGE> ans;
	
	sort(edge.begin(),edge.end(),cmpEDGE);
	
	for(auto e : edge)
	{
		int setu = findset(subset,e.u);
		int setv = findset(subset,e.v);
		if(setu != setv)
		{
			ans.push_back(e);
			subset[setu] = setv;
			if(ans.size() == V-1) break;
		}
	}
	
	unsigned long long sum = 0;
	for(auto e:ans)
		sum += e.w;
	cout<<sum;
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
		u-- , v-- , w--;
    EDGE tmp = {u,v,w};
		edge.push_back(tmp);
	}
	
	kruskal();
}
