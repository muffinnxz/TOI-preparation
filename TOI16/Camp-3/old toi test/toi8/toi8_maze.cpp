#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int n, m, sx, sy, ex, ey;
pi maze[151][151];

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> sx >> sy;
	cin >> ex >> ey;
	
	sx--, sy--, ex--, ey--;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> maze[i][j].first;
			maze[i][j].second = 0;
		}
	
	queue<pair<pi, pi> > q;
	
	q.push({{0, 2}, {sx, sy}});
	q.push({{0, 3}, {ex, ey}});
	
	maze[sx][sy].first = 2;
	maze[ex][ey].first = 3;
	
	
	int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
	while(!q.empty())
	{
		int level = q.front().first.first, zone = q.front().first.second, x = q.front().second.first, y = q.front().second.second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx = x+dir[i][0], yy = y+dir[i][1];
			if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			if(maze[xx][yy].first == 1) 
			{
				maze[xx][yy] = make_pair(zone, level+1);
				q.push({{level+1, zone}, {xx, yy}});
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout << maze[i][j].first;
		cout << "\n";
	}
	
	cout << "\n";
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout << maze[i][j].second;
		cout << "\n";
	}
	
	int bomb = 0, path = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(maze[i][j].first == 0)
			{
			}
}
