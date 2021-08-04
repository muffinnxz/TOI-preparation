#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

long long n,m,k,t;

vector<pair<long long,long long> > graph[100001];
set<long long> path;

long long dist[2][100001];

void dijkstraAlgorithm(long long x,long long src,long long dest)
{
	long long visited[n+1];
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
	
	for(long long i=0;i<=n;i++)
		dist[x][i] = INT_MAX;
	memset(visited,false,sizeof(visited));
	
	q.push(make_pair(0,src));
	dist[x][src] = 0;
	
	long long u;
	for(long long i=0;i<n;i++)
	{
		u = q.top().second;
		q.pop();
		
		visited[u] = true;
		
		for(auto v : graph[u])
		{
			if(!visited[v.first] && dist[x][u] + v.second < dist[x][v.first])
			{
				dist[x][v.first] = dist[x][u] + v.second;
				q.push(make_pair(dist[x][v.first],v.first));
			}
		}
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k>>t;
	
	long long u,v,w;
	vector<pair<pair<long long,long long> , long long> > in_use;
	for(long long i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		in_use.push_back(make_pair(make_pair(u,v),w));
		graph[u].push_back(make_pair(v,w));
		graph[v].push_back(make_pair(u,w));
	}
	
	dijkstraAlgorithm(0,1,n);
	dijkstraAlgorithm(1,n,1);
	
	long long ans = dist[0][n];
	
	for(long long i=0;i<m;i++)
	{
		if(k >= in_use[i].second) continue;
		
		u = in_use[i].first.first;
		v = in_use[i].first.second;
		long long new_dist = min(k + dist[0][u] + dist[1][v] , k + dist[0][v] + dist[1][u]);
		
		ans = min(ans,new_dist);
	}
	
	if(ans <= t) cout<<"Happy Winnie the Pooh :3\n"<<ans;
	else cout<<"No Honey TT";
}
