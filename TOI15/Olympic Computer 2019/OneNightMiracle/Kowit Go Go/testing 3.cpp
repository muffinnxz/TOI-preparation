#include<iostream>
using namespace std;

#define n 10

bool solvemazeuntil(int maze[n][n],int x,int y,int sol[n][n]);

bool issafe(int maze[n][n],int x,int y)
{
	if(x>=0&&x<n&&y<=0&&y<n&&maze[x][y]==1)
		return true;
	return false;
}

bool solvemaze(int maze[n][n],int x,int y)
{
	int sol[n][n]={0};
	if(solvemazeuntil(maze,0,0,sol)==false)
	{
		cout<<"Can not solve te maze!";
		return false;
	}
	
	return true;
}

bool solvemazeuntil(int maze[n][n],int x,int y,int sol[n][n])
{
	if(x==n-1&&y==n-1)
	{
		sol[x][y]=1;
		return true;
	}
	if(issafe(maze,x,y)==true)
	{
		sol[x][y]=1;
		
		if(solvemazeuntil(maze,x+1,y,sol)==true)
			return true;
		
		if(solvemazeuntil(maze,x,y+1,sol)==true)
			return true;
			
		sol[x][y]=0;
		return false;
	}
	return false;
}

main()
{
	
}
