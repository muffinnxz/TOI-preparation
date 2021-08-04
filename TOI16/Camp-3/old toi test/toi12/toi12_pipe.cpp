#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k;
	cin>>n>>k;
	
	pair<int,int> h[n];
	int dist[n];
	bool visited[n];
	
	memset(visited,false,sizeof(visited));
	for(int i=0;i<n;i++)
	{
		cin>>h[i].first>>h[i].second;
		dist[i] = INT_MAX;
	}
		
	int u = 0, v = 0, md;
	while(true)
	{
		u = v;
		visited[u] = true;
		md = INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(visited[i]) continue;
			dist[i] = min(dist[i], abs(h[i].first - h[u].first) + abs(h[i].second - h[u].second));
			if(dist[i] < md) 
			{
				md = dist[i];
				v = i;
			}
		}
		if(u == v) break;
	}
	
	sort(dist, dist+n);
	
	long long int sum = 0;
	for(int i=0;i<n-k;i++)
		sum += dist[i];
	cout<<sum;
}
