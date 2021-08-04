#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	pair<int,int> house[n];
	int dist[n];
	bool visited[n];
	
	for(int i=0;i<n;i++)
	{
		cin >> house[i].first >> house[i].second;
		dist[i] = INT_MAX;	
	}
	
	int u = 0, v = 0, mn;
	memset(visited,false,sizeof(visited));
	
	while(true)
	{
		u = v;
		visited[u] = true;
		mn = INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(visited[i]) continue;
			dist[i] = min(dist[i], abs(house[i].first - house[u].first) + abs(house[i].second - house[u].second));
			if(dist[i] < mn)
			{
				mn = dist[i];
				v = i;
			}
		}
		if(u == v) break;
	}
	
	sort(dist, dist+n);

	long long int sum = 0;
	for(int i=0;i<n-k;i++)
		sum += dist[i];
	cout << sum;
}
