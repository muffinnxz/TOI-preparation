#include<bits/stdc++.h>
using namespace std;

int maze[8][8] = {{0,0,0,0,0,0,0,0},
				  {0,0,1,1,1,0,1,0},
				  {0,1,1,0,1,0,1,0},
				  {0,0,1,0,1,1,1,0},
				  {0,1,1,0,1,0,0,0},
				  {0,1,0,1,1,1,1,0},
				  {0,1,0,0,0,1,0,0},
				  {0,0,0,0,0,0,0,0}};
bool visited[8][8];

void init()
{
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			visited[i][j] = false;
}

void printmaze()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			cout<<maze[i][j]<<" ";
		cout<<endl;
	}
}

bool checkMove(int x,int y,int a,int b)
{
	if(maze[x+a][y+b] == 0 || visited[x+a][y+b]) return false;
	return true;
}

void solvemaze(int x,int y,int endx,int endy)
{
	stack<pair<int,int> > path;
	init();
	
	path.push(make_pair(x,y));

	pair<int,int> u;
	bool found = false;
	while(!path.empty())
	{
		u = path.top();

		maze[u.first][u.second] = 2;
		visited[u.first][u.second] = true;
		
		if(u.first == endx && u.second == endy) {
			found = true;
			break;
		} 
		
		if(checkMove(u.first,u.second,1,0)) path.push(make_pair(u.first+1,u.second));
		else if(checkMove(u.first,u.second,-1,0)) path.push(make_pair(u.first-1,u.second));
		else if(checkMove(u.first,u.second,0,1)) path.push(make_pair(u.first,u.second+1));
		else if(checkMove(u.first,u.second,0,-1)) path.push(make_pair(u.first,u.second-1));
		else { 
			maze[u.first][u.second] = 1; path.pop();
		}
	}
	if(found) printmaze();
	else cout<<"Can't reach the end!";
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	solvemaze(1,4,1,6);
}
