#include<bits/stdc++.h>
#include<queue>
#define endll "\n"
using namespace std;
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin>>n>>m;
	
	int CaveMap[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>CaveMap[i][j];
			
	int dir[2][6][2] = {{{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,1}, {1,1}}, {{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,-1}, {1,-1}}};
	
	int nx = (n-1)/2, ny = 0, s = 0;
	bool visited[n][m][2520];
	memset(visited, false, sizeof(visited));
	
    queue<pair<int, pair<int,int> > > q;
	q.push(make_pair(0,make_pair(nx, -1)));
	
	while(!q.empty())
	{
		nx = q.front().second.first;
		ny = q.front().second.second;
		s = q.front().first + 1;
		q.pop();
		
		if(nx == (n-1)/2 && ny == m-1)
		{
			cout << s - 1;
			break;
		}
		
		for(int i=0;i<6;i++)
		{
			int next_x = nx + dir[nx%2][i][0], next_y = ny + dir[nx%2][i][1];
			if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
			if(!visited[next_x][next_y][s%2520] && CaveMap[next_x][next_y] != 0 && (s % CaveMap[next_x][next_y] == 0))
			{
				visited[next_x][next_y][s%2520] = true;
				q.push(make_pair(s, make_pair(next_x, next_y)));	
			}	
		}
	}
}
