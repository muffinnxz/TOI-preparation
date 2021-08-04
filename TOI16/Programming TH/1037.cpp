#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	char tmp;
	int land[n][m];
	queue<pair<int,int> > q;
	pair<int,int> pos,start,dest;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>tmp;
			if(tmp == 'X') land[i][j] = 0;
			else if(tmp == '*') land[i][j] = 0 , q.push(make_pair(i,j));
			else 
			{
				land[i][j] = INT_MAX;
				if(tmp == 'S') start.first = i , start.second = j;
				else if(tmp == 'D') dest.first = i , dest.second = j;
			}
		}
	

	int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
	while(!q.empty())
	{
		pos = q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int nextx = pos.first + dir[i][0] , nexty = pos.second +dir[i][1];
			if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m ) continue;
			if(nextx == dest.first && nexty == dest.second) continue;
			if(land[pos.first][pos.second] + 1 < land[nextx][nexty])
			{
				land[nextx][nexty] = land[pos.first][pos.second] + 1;
				q.push(make_pair(nextx,nexty));
			}
		}
	}
	
	int dist[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			dist[i][j] = INT_MAX;
	
	dist[start.first][start.second] = 0;
	q.push(make_pair(start.first,start.second));
	
	while(!q.empty())
	{
		pos = q.front();
		q.pop();
		
		for(int i=0;i<4;i++)
		{
			int nextx = pos.first + dir[i][0] , nexty = pos.second +dir[i][1];
			if(nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
			if(dist[pos.first][pos.second] + 1 < land[nextx][nexty] && dist[pos.first][pos.second] + 1 < dist[nextx][nexty])
			{
				dist[nextx][nexty] = dist[pos.first][pos.second] + 1;
				q.push(make_pair(nextx,nexty));
			}
		}
	}
	
	if(dist[dest.first][dest.second] == INT_MAX) cout<<"KAKTUS";
	else cout<<dist[dest.first][dest.second];
}
