#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

int n,m;
int maze[151][151];
int path = 0,mindist = INT_MAX;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
pair<int,int> start,dest;

typedef struct Node{
	int x,y,d;

	Node(int a,int b,int c) {
		x = a, y = b, d = c;
	}
	Node(){}
}Node;

void colorArea(int x,int y,int p)
{
	if(x < 1 || x > n || y < 1 || y > m) return;
	if(maze[x][y] == 0 || maze[x][y] == p) return;
	
	maze[x][y] = p;
	
	for(int i=0;i<4;i++)
		colorArea(x + dir[i][0],y + dir[i][1],p);
}

bool isBombPath(int x,int y)
{
	int startArea = 0 , destArea = 0;
	for(int i=0;i<4;i++)
		if(maze[x + dir[i][0]][y + dir[i][1]] == 2) startArea++;
		else if(maze[x + dir[i][0]][y + dir[i][1]] == 3) destArea++;
	return startArea > 0 && destArea > 0;
}

void checkpath()
{
	if(maze[start.first][start.second] == 0) return;
	
	int dist[n+2][m+2];
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
		{
			if(i == 0 || j == 0 || i == n+1 || j == m+1) dist[i][j] = 0;
			else dist[i][j] = INT_MAX;
		}
		
	queue<Node> q;
	q.push(Node(start.first,start.second,1));
	
	Node tmp;
	int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	
	bool isPath = false;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		
		for(int i=0;i<4;i++)	
		{
			int nextx = tmp.x + dir[i][0] , nexty = tmp.y + dir[i][1];
			if(maze[nextx][nexty] != 0 && tmp.d + 1 < dist[nextx][nexty])
			{
				dist[nextx][nexty] = tmp.d + 1;
				Node next = {nextx,nexty,tmp.d + 1};
				q.push(next);
			}
		}
	}
	
	mindist = min(mindist,dist[dest.first][dest.second]);	
}

main()
{
	cin>>n>>m>>start.first>>start.second>>dest.first>>dest.second;
	
	memset(maze,0,sizeof(maze));
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>maze[i][j];
			
	if(maze[start.first][start.second] == 0 || maze[dest.first][dest.second] == 0)
	{
		maze[start.first][start.second] = 1;
		maze[dest.first][dest.second] = 1;
		checkpath();
		cout<<"1\n"<<mindist;
	}
	else 
	{
		colorArea(start.first,start.second,2);
		colorArea(dest.first,dest.second,3);
		int path = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(maze[i][j] != 0) continue;
				if(isBombPath(i,j))
				{
					path++;
					maze[i][j] = 1;
					checkpath();
					maze[i][j] = 0;
				} 
			}
		cout<<path<<endll;
		cout<<mindist;
	}
	
}
