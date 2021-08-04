#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int far = 0;
bool rock[500001];
bool visited[500001];
vector<int> warp[500001];

void travel(int x)
{
	visited[x] = true;
	far = max(far,x);
	
	if(x >= n) return;
	
	if(!rock[x] && !visited[x+1]) travel(x+1);
	
	if(!warp[x].empty())
		for(auto v : warp[x])
			if(!visited[v]) travel(v);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;
	
	memset(rock,false,sizeof(rock));
	memset(visited,false,sizeof(visited));
	
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		warp[u].push_back(v);
	}
	
	for(int i=0;i<k;i++)
	{
		cin>>u;
		rock[u] = true;
	}
	
	travel(1);
	if(far == n) cout<<"1";
	else cout<<"0 "<<far;
}
